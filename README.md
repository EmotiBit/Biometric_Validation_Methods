# Biometric Validation Methods
Welcome to the EmotiBit Biometric Validation Methods repository!

Here, you can find the methodology, structure, and instructions for testing biometric algorithms. In addition, you can find data files for every version of a procedure that we release. Each procedure release contains the EmotiBit data alongside the ground-truth data (from another device) so that an EmotiBit algorithm can be compared with other EmotiBit algorithms and/or other devices.

The goal is to standardize methods used for scoring the accuracy of algorithms that detect biometric signals. Different conditions (i.e. sitting still, standing, running) can cause problems for algorithms that detect biometric signals, so these methodologies are meant to be able to standardize the way we check accuracy in different environments.

## Definitions
The following definitions apply to the scope of this repo along with all aspects of the general EmotiBit algorithm methodology.
- **Algorithm:** Code that takes in raw data (PPG, temperature, etc.) to calculate and output a derivative metric (SpO2, heartrate, etc.). 
  - A derivative metric from an algorithm can then be used as input for another algorithm
- **Instructions:** There are three different types of instructions:
  - **Device** instructions contain data collection instructions for a specific device
  - **Procedure** instructions contain steps with the goal of manipulating biometric signals
  - **Utility** instructions contain steps for supporting tasks such as data synchronization, calibration, or other auxiliary operations needed during testing.
- **Dataset:** A collection of data files containing the data from the third-party device and the EmotiBit, usually grouped in a `.zip` archive.

**Note on datasets:** As a general rule, files that comes out of the same `.zip` file can be directly compared with each other since they are from the same "run" of the test procedure. However, if a test procedure contains several different datasets under the same release, then files from different datasets cannot be directly compared since it is very likely that they come from different "runs" of the test.

## Using this repository
### I want to test a new **algorithm**
To start, test your algorithm by using the data from a particular procedure release (ex. [sit-stand-sit_v0.0.0](https://github.com/EmotiBit/Biometric_Validation_Methods/releases/tag/sit-stand-sit_v0.0.0)). From there, generate scores for how well it performs on the EmotiBit data when compared to a third-party "ground-truth" device (also provided in the procedure release) using `scorer.py` in the EmotiBit Biometric Lib repository (refer to this [example](https://github.com/EmotiBit/EmotiBit_Biometric_Lib/tree/dev/py/examples/scorer_example) for instructions on how to use `scorer.py`). 

`scorer.py` will generate plots comparing the EmotiBit data to the ground-truth data to visualize and quantify the algorithm's performance. Put these plots in the appropriate subdirectories of the `tests` folder along with showing them in the README of your algorithm (refer to this [SpO2 algorithm](https://github.com/EmotiBit/EmotiBit_Brainflow_SpO2_Algorithm)).
- As mentioned before, the release for a procedure includes the data files that were recorded when that test was created/last updated. If your algorithm is able to calculate the metric post-hoc, then you can use these raw data files to calculate your metric (ex. using [Python](#running-algorithms-on-a-pc) to run the algorithm).
- If your algorithm must be run live then you will need to collect new data. When doing so, you will need to also collect data from a ground truth device so that you can compare performance and generate scores. These new data files should be included in the algorithm repo.

### I want to add new **instructions**
A new procedure is added by having the newly created markdown file (containing description, instructions, etc.) added to this repository. Refer to any of the existing instructions for examples of what to include for each category of instructions.

To properly version the procedure, use the [versioning structure.](#versioning-structure)

### I want to add a new **dataset**
To add data from a new device to an existing procedure, follow the selected procedure instructions (as well as other utility instructions needed for synchronization, etc.) while recording data from the EmotiBit and the new device. Put the files in a directory together named following the [naming convention](#naming-convention) below so that they can be added to the release for that specific version of the procedure.

In addition, if there are device-specific instructions that need to be followed for data collection, create a PR to add the new device instruction file to this repo.

**Note:** If you have the capability to record more than one third-party device at the same time alongside the EmotiBit, it is recommended to create a `.zip` archive for each device-EmotiBit pairing. For example, if you record data from `hr-sensor`, `spo2-sensor`, and from the EmotiBit when following one procedure, then the `hr-sensor` should have its own archive w/ EmotiBit data, and the `spo2-sensor` should also have its own archive as well.

## Synchronization
When it comes to comparing data between two devices (a third-party and the EmotiBit), proper synchronization is imperative for accurate results. This responsibility mainly rests on whoever is recording new datasets. Different methods for accurate synchronization are mentioned below:
* **Use the notes feature in the EmotiBit oscilloscope to input data straight into the EmotiBit data stream:** This method is very simple and temporally accurate as each user note is given an EmotiBit timestamp in the EmotiBit's own `.csv` file. However, this approach is very limited by input speed since the user needs to input data manually (limiting frequency and number of data types able to be collected).
* **Use an alignment procedure:** In utility category under `instructions`, there are different procedures designed for syncing data between the EmotiBit and other devices.
  * Alignment procedures should describe minimum hardware required for a the procedure to be possible on a third-party device (ex. accelerometer required for tapping procedure)

## Running algorithms on a PC
Many algorithms are able to be compiled into a Python module using `pybind`, enabling algorithms that run on the EmotiBit to be tested and iterated on a PC using pre-recorded data. This has several advantages such as faster development cycles and easy integration with other Python libraries to perform analysis and generate plots.

For detailed instructions on how to build an algorithm for Python using pybind or setup pybind for an algorithm, refer to the EmotiBit Plugins [repository](https://github.com/EmotiBit/EmotiBit_Plugins/tree/main).

## Naming Convention
Each procedure release contains data from the EmotiBit alongside ground-truth data from another device (ex. Cyton). The data files from the procedure are grouped together in a zip file, named as `<procedure-name>_v<X.Y.Z>_<device>.zip`. For example, if EmotiBit data was recorded alongside Cyton data following the sit-stand-sit_v0.0.0 procedure, then the `.zip` containing the data files in the release would be named `sit-stand-sit_v0.0.0_cyton.zip`.

The structure of the `.zip` archive should resemble the following (as an example):
```
sit-stand-sit_v0.0.0_cyton.zip/
├── emotibit-data/
│   └── EmotiBit.csv
└── cyton-data/
    ├── cyton2.csv
    ├── cyton1.csv
    └── ...
```

This ensures that data recorded at the same time on different devices using the same procedure remains grouped together, while data recorded using the same procedure but at a different time (such as to record data for a new device) is not accidentally compared with "incompatible" data.

## Versioning Structure

All instructions have their own version that can vary independently of other instructions. Version structure follows this pattern: `X.Y.Z`

The number in the `X` position denotes a change in the instructions that makes it **incompatible** with data collected using those instructions with a different `X` version.

The number in the `Y` position denotes a change to the instructions that was only made to support another device. Instructions with different `Y` versions are still compatible with each other as long as they have the same `X` version.

The number in the `Z` position denotes a change that does not have any effect on the instructions, such as fixing a typo or updating a screenshot in the instructions. Similar to changes in `Y`, instructions with different `Z` versions are still compatible with each other as long as they have the same `X` version.

Any changes that are in the "gray area" are immediately considered an incompatible change.

For more information on the philosophy behind this versioning structure, see [semantic versioning.](https://semver.org/spec/v2.0.0.html)

## Definition of Compatibility
**Important:** If two procedures are compatible, it does not imply that the data from these procedures is from the same data session.
- In order to generate plots between two files using `scorer.py`, they need to from the same recording session 
- If two procedures are compatible then the plots can be compared against each other 

For example, if you have the following data:
1. EmotiBit and Cyton file recorded with `v1.2.4`
1. EmotiBit and Muse file recorded with `v1.3.5`
1. EmotiBit and Cyton file recorded with `v2.2.1`
1. EmotiBit and Muse file recorded with `v2.2.1` *(from a different recording session than the Cyton file)*

The files in 1 can be directly compared with each other and plots can be generated between the two files, as they are from the recording session. The same applies for 2, 3, and 4.

In addition, you can compare the plots generated in 1 to the plots generated in 2, but the plots from 1 and 2 cannot be compared to the plots from either 3 or 4. 

Furthermore, while the plots from 3 and 4 can be compared, the Muse file from 4 cannot be directly compared with the Cyton or EmotiBit file from 3 since they are different recording sessions.

## Releases

Whenever a change is made to a procedure that increments either the `X` or the `Y` in the `X.Y.Z` structure, a new release is made. This happens because a change to either of these indicates that new data was collected.

Releases are tagged with the following structure: `<procedure-name>_vX.Y.Z` This allows procedures to get new versions independent of other procedures changing or staying the same.

When a release is made, it contains the following:
- A description of what is contained in the release/what the changes are
- A link to the source code at the time of release (which lets you see the definition of the procedure at this release)
- The new dataset(s) that were recorded with this new version of the procedure