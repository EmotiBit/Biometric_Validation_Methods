# Biometric Validation Methods
Welcome to the EmotiBit Biometric Validation Methods repository!

Here, you can find the methodology, structure, and procedures for our biometric algorithms. In addition, you can find data files for every new version of a test procedure that we release as part of a release. Each test procedure contains the EmotiBit data alongside the ground-truth data (collected from another device) so that different EmotiBit algorithms can be compared to other devices using the same datasets.

The goal is to be able to establish methodologies that work towards standardizing the methods used for scoring the accuracy of algorithms that detect biometric signals. Different conditions (i.e. sitting still, standing, running) can cause problems for algorithms that detect biometric signals, so these methodologies are meant to be able to standardize the way we check accuracy in many different scenarios.

## Definitions
The following definitions apply to the scope of this repo along with all aspects of the general EmotiBit algorithm validation methodology.
- **Algorithm:** Code that takes in raw data (PPG, temperature, etc.) to calculate and output a derivative metric (SpO2, heartrate, etc.). 
- **Procedure:** A standardized set of instructions detailing different actions/environments for the purpose of data collection. These are **non-device specific** (ex. sit-stand-sit) and are sorted under two categories:
  1) **Test** procedures involve human actions with the intention of altering biometric conditions for the use of algorithm validation (ex. running, holding breath).  
  **Note:** The terms **test** and **test procedure** can be used interchangibly.
  2) **Utility** procedures can still involve human actions, but they are not designed to change a biometric signal such as temperature or heart rate.
- **Dataset:** A collection of data files collected using a specific procedure containg the data from the third-party device and the EmotiBit.

## Using this repository
This section describes the different things you may want to do with this respository and how they would be accomplished.

### I want to test a new **algorithm**
To start, test your algorithm by using the data from a particular procedure release (ex. [sit-stand-sit_v0.0.0](https://github.com/EmotiBit/Biometric_Validation_Methods/releases/tag/sit-stand-sit_v0.0.0)) and device. From there, generate scores for how well it performs on the input test data when compared to a gold standard for measuring the metric you are interested in (also provided in the procedure release) using the `scorer.py` in the EmotiBit_Biometric_Lib [repository](https://github.com/EmotiBit/EmotiBit_Biometric_Lib) in the `emotibit` Python module under the `py` directory. In addition, `scorer.py` will generate plots comparing the EmotiBit data to the gold standard data so that the algorithm's performance is visible (an example of how to generate the scores and plots is [provided](https://github.com/EmotiBit/EmotiBit_Biometric_Lib/tree/master/py/examples/scorer_example) in the EmotiBit_Biometric_Lib repository). After having generated scores and the plots, include them in the README of your algorithm as well as putting them in the appropriate subdirectories of the `assets` folder (refer to the directory tree below or this [SPO2 algorithm](https://github.com/EmotiBit/BrainflowSpO2Algorithm) for an example of what the repository should look like).

```
MyAwesomeAlgorithm/
├── assets/
│   └── tests/
│       └── sit-stand-sit_v0.0.0/
│           └── <device>/
│               ├── <device>_scatter.png
│               ├── <device>_resampled.png
│               └── <device>_mean-diff.png
├── src/
│   ├── MyAwesomeAlgorithm.h
│   └── MyAwesomeAlgorithm.cpp
├── pybind/
│   ├── build/
│   │   └── ...
│   ├── venv/
│   │   └── ...
│   ├── bindings.cpp
│   ├── run.py
│   └── CMakeLists.txt
├── library.properties
└── README.md
```

As mentioned before, the release for a procedure includes the data files that were recorded when that procedure was created/last updated. If your algorithm is able to detect the metric post-hoc, then you can use these raw data files to calculate your metric. Once the metric has been calculated, use the data file from the gold standard device to compare against and generate scores for the table. This should be done for relevant procedures so that an understanding of how the algorithm performs under many different conditions can be achieved.

If your algorithm must be run live then you will need to collect new data. When doing so, you will need to also collect data from a gold-standard device so that you can compare performance and generate scores. These new data files should be included in the associated procedure release.

### I want to add a new **procedure**
A new procedure is added by having the newly created markdown file (containing description, instructions, etc.) added to this repository. Refer to any of the existing procedures for examples of what to include in the instructions.

To properly version the procedure, use the [versioning structure.](#versioning-structure)

### I want to add a new **dataset**
To add data from a new device to an existing test procedure, follow the selected test procedure (as well as an other utility procedures needed for synchronization, etc.) while recording data from the EmotiBit and from the new device. Put the files in a directory together named following the [naming convention](#naming-convention) below so that they can be added to the release for that specific version of the procedure along with any notes/instructions.

**Note:** If possible, try to include non-parsed data files in the dataset. However, if a non-EmotiBit device requires a specialized program/script to parse the data, then the parsed files can be included in the dataset along with the original data file.

**Note:** If you have the capability to record 3 or more devices at the same time alongside the EmotiBit, it is recommended to create a `.zip` archive for each device-EmotiBit pairing. For example, if you record data from `hr-sensor`, `spo2-sensor`, and from the EmotiBit when following one test procedure, then the `hr-sensor` should have its own archive w/ EmotiBit data, and the `spo2-sensor` should also have its own archive.

## Synchronization
When it comes to comparing data between two devices (a third-party and the EmotiBit), proper synchronization is imperative for accurate results. This responsibility mainly rests on whoever is recording new datasets. Different methods for accurate synchronization are mentioned below:
* **Use the notes feature in the EmotiBit oscilloscope to input data straight into the EmotiBit data stream:** This method is very simple and accurate as each user note is given an EmotiBit timestamp in the EmotiBit's own `.csv` file. However, this approach is very limited by input speed since the user needs to input data manually (limiting frequency and # of different data able to be collected).
* **Use an alignment procedure:** In utility category under `procedures`, there are different procedures designed for syncing data between the EmotiBit and other devices.
  * Alignment procedures should describe minimum hardware required for a the procedure to be possible on a third-party device (ex. accelerometer required for tapping procedure)

## Naming Convention
Each procedure release contains data from the EmotiBit alongside ground-truth data from another device (ex. Cyton). The data files from the procedure are grouped together in a zip file, named as `<procedure-name_<vX.Y.Z>_<device>.zip`. For example, if EmotiBit data was recorded alongside Cyton data following the sit-stand-sit_v0.0.0 procedure, then the zip containing the data files in the release would be named `sit-stand-sit_v0.0.0_cyton.zip`.

The structure of the `.zip` archive should resemble the following (as an example):
```
sit-stand-sit_v0.0.0_cyton.zip/
├── emotibit-data/
│   └── EmotiBit.csv
├── cyton-data/
│   ├── cyton1.csv
│   ├── cyton2.csv
│   └── ...
└── README.md
```

This ensures that data recorded at the same time on different devices using the same procedure remains grouped together, while data recorded using the same procedure but at a different time (such as to record data for a new device) is not accidentally compared with "incompatible" data.

## Versioning Structure

All procedures have their own version that can and does vary independently of other procedures. The structure for their version follows this pattern: ```X.Y.Z```

The number in the ```X``` position denotes a change in the procedure that makes it [incompatible](#definition-of-compatibilitiy) with data collected using that The number in the ```X``` position denotes a change in the procedure that makes it [incompatible](#definition-of-compatibilitiy) with data collected using that The number in the ```X``` position denotes a change in the procedure that makes it [incompatible](#definition-of-compatibilitiy) with data collected using that The number in the ```X``` position denotes a change in the procedure that makes it [incompatible](#definition-of-compatibilitiy) with data collected using that procedure with a different ```X``` version. For example, version ```1.4.2``` is [compatible](#definition-of-compatibilitiy) with version ```1.6.1```, but not [compatible](#definition-of-compatibilitiy) with version ```0.2.5``` or version ```2.9.1```.
 with a different ```X``` version. For example, version ```1.4.2``` is [compatible](#definition-of-compatibilitiy) with version ```1.6.1```, but not [compatible](#definition-of-compatibilitiy) with version ```0.2.5``` or version ```2.9.1```.
 with a different ```X``` version. For example, version ```1.4.2``` is [compatible](#definition-of-compatibilitiy) with version ```1.6.1```, but not [compatible](#definition-of-compatibilitiy) with version ```0.2.5``` or version ```2.9.1```.
 with a different ```X``` version. For example, version ```1.4.2``` is [compatible](#definition-of-compatibilitiy) with version ```1.6.1```, but not [compatible](#definition-of-compatibilitiy) with version ```0.2.5``` or version ```2.9.1```.

The number in the ```Y``` position denotes a change to the procedure that was only made to support another device. The procedure structure has not changed, it has just had modifications made to indicate how to use another device with the procedure. procedures with different ```Y``` versions are still [compatible](#definition-of-compatibilitiy) with each other as long as they have the same ```X``` version. For example, version ```1.2.4``` is [compatible](#definition-of-compatibilitiy) with version ```1.3.4``` but not with version ```2.2.4```.

The number in the ```Z``` position denotes a change that does not have any affect on the procedure, such as fixing a typo or updating a screenshot in the procedure. Procedures with different ```Z``` versions are still [compatible](#definition-of-compatibilitiy) with each other as long as they have the same ```X``` version. For example, version ```1.2.3``` is [compatible](#definition-of-compatibilitiy) with version ```1.2.4``` and version ```1.3.2``` but not with version ```2.2.3```.

Any changes that are in the "gray area" are immediately considered an incompatible change.

For more information on the philosophy behind this versioning structure, see [semantic versioning.](https://semver.org/spec/v2.0.0.html)

## Definition of Compatibilitiy

The previous section references procedures being "compatible" with each other several times. In this section, we define what it means for two procedure versions to be compatible.

**Important:** If two procedures are compatible it does not mean that the data from these procedures is the exact same recording. This means that you cannot necessarily directly compare two recordings and generate a score between them just because their procedure version is compatible since those two recordings are not from the same data session. 

In order to generate a score between two files, they need to explicitly be the same recording, which by definition requires that they were both recorded on the same version. If two procedures are compatible it means that if you compare scores between the procedures, it is a valid comparison. 

For example, if you have the following data:
1. An EmotiBit and a Cyton file recorded with ```v1.2.4```
2. An EmotiBit and aBrainFlow file recorded with ```v1.3.5```
3. An EmotiBit and a Cyton file recorded with ```v2.2.1```
4. An EmotiBit and a aBrainFlow file recorded with ```v2.2.1``` *from a different session than the Cyton file*

The files in 1 can be directly compared with each other and a score can be generated between the two files, as they are the same recording, just on two different devices, the same applies for 2, 3, and 4.

In addition, you can compare the score generated in (1) to the score generated in (2), and it will be a valid comparison, but 1 and 2 cannot be compared to either 3 or 4. Furthermore, while the scores from 3 and 4 can be compared, the aBrainFlow file from 4 cannot be directly compared with the Cyton or EmotiBit file from 3.

## Releases

Whenever a change is made to a procedure that increments either the ```X``` or the ```Y``` in the ```X.Y.Z``` structure, a new release is made. This happens because a change to either of these indicates that new data was collected.

Releases are tagged with the following structure: ```<procedure-name>_vX.Y.Z``` This allows procedures to get new versions independent of other procedures changing or staying the same.

When a release is made, it contains the following:
- A description of what is contained in the release/what the changes are
- A link to the source code at the time of release (which lets you see the definition of the procedure at this release)
- The new data files that were recorded with this new version of the procedure.