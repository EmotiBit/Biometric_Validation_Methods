# Biometric Validation Methods

Welcome to the EmotiBit Biometric Validation Methods repository!

The goal is to standardize methods used for scoring the accuracy of algorithms that detect biometric signals. 
This repository provides standardized methods for validating biometric algorithms across different conditions (sitting, standing, running, etc.).

## What you can do with this repository

1. **Test your algorithm** - Evaluate algorithm performance using provided datasets 
2. **Add a new test** - Create a new test that will be used to evaluate algorithms
3. **Add a new dataset** - Add new datasets for existing tests for new devices

## Definitions

The following definitions apply to the scope of this repo along with all aspects of the general EmotiBit algorithm methodology:

- **Algorithm:** Code that takes in raw data (PPG, temperature, etc.) to calculate and output a derivative metric (SpO2, heart rate, etc.)
  - A derivative metric from an algorithm can then be used as input for another algorithm
- **Test:** Steps that manipulate biometric signals under specific conditions (e.g., sit-stand-sit, hold-breath)
- **Ground-Truth Device:** A reference device used to provide accurate measurements for comparison against EmotiBit algorithm outputs
- **Device Protocol:** Steps that describe how to collect data from a ground-truth device
- **Utility Protocol:** Supporting tasks such as data synchronization, calibration, or other auxiliary operations needed during testing
- **Run:** A single execution of a test where data is recorded simultaneously from EmotiBit and a ground-truth device
- **Dataset:** A collection of data files from one run, usually grouped in a `.zip` archive (refer to [naming convention](#naming-convention) for file structure)

**Note on datasets:** Files within the same dataset can be directly compared since they were recorded simultaneously. Files from different datasets cannot be directly compared, even if from the same test release, since they come from different runs.

## Using this repository

### I want to evaluate a new **algorithm**

1. Download a dataset from a test release (e.g., [sit-stand-sit_v0.0.0](https://github.com/EmotiBit/Biometric_Validation_Methods/releases/tag/sit-stand-sit_v0.0.0))
2. Run your algorithm on the EmotiBit data from the dataset
3. Use [`scorer.py`](https://github.com/EmotiBit/EmotiBit_Biometric_Lib/blob/a82244efcccb6512258c802b8eebd2d1895d8990/py/src/emotibit/scorer.py#L2) to compare your algorithm output against the ground-truth device data
    - `scorer.py` will generate plots comparing the EmotiBit data to the ground-truth data to visualize and quantify the algorithm's performance.
4. Review the generated plots and scores

**Note**: *This process is designed for algorithms that can run post-hoc, thus leveraging the raw data collected, at the time of creation of the **release**. If your algorithm must be run live then you will need to collect new data. When doing so, you will need to also collect data from a ground truth device so that you can compare performance and generate scores.*

### I want to add a new test
These instructions define a new test, that will be used to benchmark algorithms.
New instructions are added by having the newly created markdown file (containing description, steps, etc.) added to this repository. Refer to any of the existing instructions for examples of what to include for each category of instructions.
- See [tests](./tests/)

TODO: Add more details

### I want to add a new ground-truth device
These instructions define the steps to record data from a ground-truth device.
- See [device-protocols](./device-protocols/)

TODO: Add more details

### I want to add a new **dataset** (for an existing test)
Combine the instructions for (1) how to record data from a ground-truth device and (2) steps to perform a test. Put the files in a directory together named following the [naming convention](#naming-convention) below so that they can be added to the release for that specific version of the procedure.

**Note:** If you have the capability to record more than one third-party device at the same time alongside the EmotiBit, it is recommended to create a `.zip` archive for each device-EmotiBit pairing. For example, if you record data from `hr-sensor`, `spo2-sensor`, and from the EmotiBit when following one procedure, then the `hr-sensor` should have its own archive w/ EmotiBit data, and the `spo2-sensor` should also have its own archive as well.

## Synchronization

When it comes to comparing data between two devices (a third-party and the EmotiBit), proper synchronization is imperative for accurate results. This responsibility mainly rests on whoever is recording new datasets. Different methods for accurate synchronization are mentioned below:

- **Use the notes feature in the EmotiBit oscilloscope to input data straight into the EmotiBit data stream:** This method is simple and temporally accurate as each user note is given an EmotiBit timestamp in the EmotiBit `.csv` file. However, this approach is limited by input speed since the user needs to input data manually (limiting frequency and number of data types)
- **Use an alignment procedure:** Check out the ["tapping prcedure"](./utility-protocols/tapping-procedure_v0.0.0.md) under "utility-protocols".

## Running algorithms on a PC

Many algorithms are able to be compiled into a Python module using `pybind`, enabling algorithms that run on the EmotiBit to be tested and iterated on a PC using pre-recorded data. This has several advantages such as faster development cycles and easy integration with other Python libraries to perform analysis and generate plots.

For detailed instructions on how to build an algorithm for Python using `pybind`, refer to the EmotiBit Plugins [repository](https://github.com/EmotiBit/EmotiBit_Plugins/tree/main).

## Naming Convention

Each procedure release contains data from the EmotiBit alongside ground-truth data from another device (ex. Cyton). The data files from the procedure are grouped together in a zip file, named as `<procedure-name>_v<X.Y.Z>_<device>.zip`. For example, if EmotiBit data was recorded alongside Cyton data following the sit-stand-sit_v0.0.0 procedure, then the `.zip` containing the data files in the release would be named `sit-stand-sit_v0.0.0_cyton.zip`.

The structure of the `.zip` archive should resemble the following (as an example):

```text
sit-stand-sit_v0.0.0_cyton.zip/
├── emotibit-data/
│   └── EmotiBit.csv
└── cyton-data/
    ├── cyton2.csv
    ├── cyton1.csv
    └── ...
```

This ensures that data recorded at the same time on different devices using the same procedure remains grouped together, while data recorded using the same procedure but at a different time (such as to record data for a new device) is not accidentally compared against "incompatible" data.

## Versioning Structure

All instructions have their own version that can vary independently of other instructions. Version structure follows this pattern: `X.Y.Z`

The number in the `X` position denotes a change in the instructions that makes scores calculated using those instructions **incompatible** with scores calculated using the same instructions with a different `X` version.

The number in the `Y` position denotes a change to the instructions that was only made to support another device. Instructions with different `Y` versions are still compatible with each other as long as they have the same `X` version.

The number in the `Z` position denotes a change that does not have any effect on the instructions, such as fixing a typo or updating a screenshot in the instructions. Similar to changes in `Y`, instructions with different `Z` versions are still compatible with each other as long as they have the same `X` version.

Any changes that are in the "gray area" are immediately considered an incompatible change.

For more information on the philosophy behind this versioning structure, see [semantic versioning.](https://semver.org/spec/v2.0.0.html)

## Definition of Compatibility

**Important:** If two procedures are compatible, it does not imply that the data from these procedures is from the same data session.

- To generate plots between two data files using `scorer.py`, they need to be from the same recording session
- If two procedures are compatible, then the final plots can be compared against each other, but not the raw data itself

For example, if you have the following data:

1. EmotiBit and Cyton file recorded with `v1.2.4`
1. EmotiBit and Muse file recorded with `v1.3.5`
1. EmotiBit and Cyton file recorded with `v2.2.1`
1. EmotiBit and Muse file recorded with `v2.2.1` *(from a different recording session than the Cyton file)*

The files in 1 can be directly compared with each other and plots can be generated between the two files, as they are from the same recording session. The same applies for 2, 3, and 4.

In addition, you can compare the plots generated in 1 to the plots generated in 2, but the plots from 1 and 2 cannot be compared to the plots from either 3 or 4.

Furthermore, while the plots from 3 and 4 can be compared, the Muse file from 4 cannot be directly compared with the Cyton or EmotiBit file from 3 since they are different recording sessions.

## Releases

Whenever a change is made to a procedure that increments either the `X` or the `Y` in the `X.Y.Z` structure, a new release is made. This happens because a change to either of these indicates that new data was collected.

Releases are tagged with the following structure: `<procedure-name>_vX.Y.Z` This allows procedures to get new versions independent of other procedures changing or staying the same.

When a release is made, it contains the following:

- A description of what is contained in the release/what the changes are
- A link to the source code at the time of release (which lets you see the definition of the procedure at this release)
- The new dataset(s) that were recorded with this new version of the procedure
