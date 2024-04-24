# Biometric_Validation_Methods
Methods for validating biometric tools

Welcome to the EmotiBit Biometric Validation Methods repository!

Here, you can find the methods we use for collecting data to validate our biometric algorithms. In addition, you can find data files for every new version of a test that we release as part of a release.

The goal is to be able to establish methodologies that work towards standardizing the methods used for scoring the accuracy of algorithms that detect biometric signals. Different conditions (i.e. sitting still, standing, running) can cause problems for algorithms that detect biometric signals, these methodologies are meant to be able to standardize the way we check accuracy in many different scenarios.

## Using the Tests
This section describes the different things you may want to do with this respository and how they would be accomplished.

### I have a new algorithm - What now?
It will become a new column in the results table for the tests. (This table is shown in a release whenever a test is added/updated). Using your algorithm, generate scores for how well it performs under the condition of a test when compared to a gold standard for measuring the metric you are intereseted in. Once you have these scores, a new column can be added to the table so that the algorithm's performance is visible. Here is an example of how the [sit_stand_sit_v0.0.0](https://github.com/EmotiBit/Biometric_Validation_Methods/releases/tag/sit-stand-sit_v0.0.0) may look with an additional algorithm added:

| Test | Algorithm 1 | [Example] Algorithm 2 |
| --- | --- | --- |
| sit-stand-sit_v0.0.0 | <table> <tr> <thead><th>Score</th><th>Plot</th></tr></thead><tbody><tr> <td><table><tr><thead><th>Scores</th><th>Value</th></thead></tr><tbody><tr><td>r</td><td>0.3225</td></tr><tr><td>rho</td><td>0.7197</td></tr><tr><td>tau</td><td>0.5497</td></tr></tbody></table></td> <td><img src="https://github.com/EmotiBit/Biometric_Validation_Methods/assets/70301946/a401e7fd-14ec-4cbc-a976-ad4879c6f004" width=150> </td></tr></tbody> </table>| <table> <tr> <thead><th>Score</th><th>Plot</th></tr></thead><tbody><tr> <td><table><tr><thead><th>Scores</th><th>Value</th></thead></tr><tbody><tr><td>r</td><td>0.123</td></tr><tr><td>rho</td><td>0.456</td></tr><tr><td>tau</td><td>0.789</td></tr></tbody></table></td> <td><img src="https://github.com/EmotiBit/Biometric_Validation_Methods/assets/70301946/a401e7fd-14ec-4cbc-a976-ad4879c6f004" width=150> </td></tr></tbody> </table>|

The release for a test includes the data files that were recorded when that test was created/last updated. If your algorithm is able to detect the metric post-hoc, then you can use these raw data files to calculate your metric. Once the metric has been calculated, use the data file from the gold standard device to compare against and generate scores for the table. This should be done for each test, so that an understanding of how the algorithm performs under many different conditions can be achieved.

If your algorithm must be run live then you will need to collect new data. When doing so, you will need to also collect data with a gold-standard device so that you can generate scores. These new data files should be included in the new release that is made. Data and scores will need to be collected and calculated for each test, following the test procedure outlined in the file for each test.

### I have a new test
To demonstrate the procedure for adding a test, we will show an example. The example will be adding a jogging test:

1. Create the test file. A template can be found [here.](./tests/README.md#test-template) Here is our example test:
```
Test Name: Jogging 
Test Version: 1.0.0  
Test Purpose: Understand how the algorithms perform in noisy conditions such as jogging
  
Test Directions:  
- Complete first part of tapping procedure.  
- Jog at a constant speed without sudden changes in direction for 5 minutes. 
- Complete second part of tapping procedure.
```
To properly version the test, use the [versioning structure.](#versioning-structure)

2. Collect the data for your test. You will need to use the devices to collect data as outlined in your new testing procedure.
2. Calculate Metric and Score. Using your collected data and the existing Algorithms for this metric, calculate the metric and calculate the score for that metric against your gold standard measurment.
2. Create a release with this information. The release should be named the name of the test with its version appended to it. It should include a description and a table showing the results of the test with the algorithms that were used with it. Additionally, the data recorded from running the test should be included as assets for the release. See an example [here.](https://github.com/EmotiBit/Biometric_Validation_Methods/releases/tag/sit-stand-sit_v0.0.0)


## Versioning Structure

All tests have their own version that can and does vary independently of other tests. The structure for their version follows this pattern: ```X.Y.Z```

The number in the ```X``` position denotes a change in the test that makes it [incompatible](#definition-of-compatibilitiy) with data collected using that test with a different ```X``` version. For example, version ```1.4.2``` is [compatible](#definition-of-compatibilitiy) with version ```1.6.1```, but not [compatible](#definition-of-compatibilitiy) with version ```0.2.5``` or version ```2.9.1```.

The number in the ```Y``` position denotes a change to the test that was only made to support another device. The test structure has not changed, it has just had modifications made to indicate how to use another device with the test. Tests with different ```Y``` versions are still [compatible](#definition-of-compatibilitiy) with each other as long as they have the same ```X``` version. For example, version ```1.2.4``` is [compatible](#definition-of-compatibilitiy) with version ```1.3.4``` but not with version ```2.2.4```.

The number in the ```Z``` position denotes a change that does not have any affect on the testing procedure, such as fixing a typo or updating a screenshot in the test procedure. Tests with different ```Z``` versions are still [compatible](#definition-of-compatibilitiy) with each other as long as they have the same ```X``` version. For example, version ```1.2.3``` is [compatible](#definition-of-compatibilitiy) with version ```1.2.4``` and version ```1.3.2``` but not with version ```2.2.3```.

Any changes that are in the "gray area" are immediately considered an incompatible change.

For more information on the philosophy behind this versioning structure, see [semantic versioning.](https://semver.org/spec/v2.0.0.html)

## Definition of Compatibilitiy

The previous section references tests being "compatible" with each other several times. In this section, we define what it means for two test versions to be compatible.

If two tests are compatible it does not mean that the data from these tests is the exact same recording. This means that you cannot necessarily directly compare two recordings and generate a score between them just because their test version is compatible.

If two tests are compatible it means that if you compare scores between the tests, it is a valid comparison. 

In order to generate a score between two files, they need to explicitly be the same recording, which by definition requires that they were both recorded on the same version.

For example, if you have the following data:
- (1) An EmotiBit and a Cyton file recorded with ```v1.2.4```
- (2) An EmotiBit and aBrainFlow file recorded with ```v1.3.5```
- (3) An EmotiBit and a Cyton file recorded with ```v2.2.1```

The files in (1) can be directly compared with each other and a score can be generated between the two files, as they are the same recording, just on two different devices, the same applies for (2) and (3).

In addition, you can compare the score generated in (1) to the score generated in (2), and it will be a valid comparison, but you cannot compare either (1) or (2) to (3).

## Releases

Whenever a change is made to a test that increments either the ```X``` or the ```Y``` in the ```X.Y.Z``` structure, a new release is made. This happens because a change to either of these indicates that new data was collected.

Releases are tagged with the following structure: ```<test-name>_vX.Y.Z``` This allows tests to get new versions independent of other tests changing or staying the same.

When a release is made, it contains the following:
- A description of what is contained in the release/what the changes are
- A link to the source code at the time of release (which lets you see the definition of the test at this release)
- The new data files that were recorded with this new version of the test.