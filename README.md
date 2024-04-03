# Biometric_Validation_Methods
Methods for validating biometric tools

Welcome to the EmotiBit Biometric Validation Methods repository!

Here, you can find the methods we use for collecting data to validate our biometric algorithms. In addition, you can find data files for every new version of a test that we release as part of a release.

## Versioning Structure

All tests have their own version. The structure for their version follows this pattern: ```X.Y.Z```

The number in the ```X``` position denotes a change in the test that makes it [incompatible](#definition-of-compatibilitiy) with data collected using that test with a different ```X``` version. For example, version ```1.4.2``` is [compatible](#definition-of-compatibilitiy) with version ```1.6.1```, but not [compatible](#definition-of-compatibilitiy) with version ```0.2.5``` or version ```2.9.1```.

The number in the ```Y``` position denotes a change to the test that was only made to support another device. The test structue has not change, it has just had modifications made to indicate how to use another device with the test. Tests with different ```Y``` versions are still [compatible](#definition-of-compatibilitiy) with each other as long as they have the same ```X``` version. For example, version ```1.2.4``` is [compatible](#definition-of-compatibilitiy) with version ```1.3.4``` but not with version ```2.2.4```.

The number in the ```Z``` position denotes a change that does not have any affect on the testing procedure, such as changing a typo or updating a screenshot in the test procedure. Tests with different ```Z``` version are still [compatible](#definition-of-compatibilitiy) with each other as long as they have the same ```X``` version. For example, version ```1.2.3``` is [compatible](#definition-of-compatibilitiy) with version ```1.2.4``` and version ```1.3.2``` but not with version ```2.2.3```.

Any changes that one thinks are in the "gray area" are immediately considered an incompatible change.

For more information on the philosophy behind this versioning structure, see [semantic versioning.](https://semver.org/spec/v2.0.0.html)

## Definition of Compatibilitiy

The previous section references tests being "compatible" with each other several times. In this section, we define what it means for two test versions to be compatible.

If two tests are compatible it does not mean that the data from these tests is the exact same recording. This means that you cannot necessarily directly compare two recordings and generate a score between them just because their test version is compatible.

If two tests are compatible it means that if you compare scores between the tests, it is a valid comparison. 

For example, if you have the following data:
- (1) An EmotiBit and Cyton file recorded with ```v1.2.4```
- (2) An EmotiBit and BrainFlow file recorded with ```v1.3.5```
- (3) An EmotiBit and Cyton file recorded with ```v2.2.1```

The files in (1) can be directly compared with each other and a score can be generated, as they are the same recording, just on two different devices, the same applies for (2) and (3).

In addition, you can compare the score generated in (1) to the score generated in (2), and it will be a valid comparison, but you cannot compare either (1) or (2) to (3).

## Releases

Whenever a change is made to a test that increments either the ```X``` or the ```Y``` in the ```X.Y.Z``` structure, a new release is made. This happens because a change to either of these indicates that new data was collected.

Releases are tagged with the following structure: ```<test-name>_vX.Y.Z``` This allows tests to get new versions independent of other tests changing or staying the same.

When a release is made, it contains the following:
- A description of what is contained in the release/what the changes are
- A link to the source code at the time of release (which lets you see the definition of the test at this release)
- The new data files that were recorded with this new version of the test.