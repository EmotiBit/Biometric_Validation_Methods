## Tests
This directory contains all of the current tests.

## Tapping Procedure
All of the tests indicate to perform the tapping procedure. The tapping procedure is used to be able to effectively line up the data streams from the devices that you are using. This section describes how to correctly perform the tapping procedure:

1. **Setup your data collection environment(s)** - Ensure that you have a working environment(s) for the devices you plan to use that allows you to record data on your devices.
1. **Launch data collection environment(s)** - Start any software/launch the environments that you will use to collect your data. Ensure that your devices have properly connected to those environment(s).
1. **Begin data recording** - Start the data recording on both of the devices that you are recording data with. Starting the recording on the devices as close as you can to each other may make further analysis more straightforward, but is not strictly necessary.
1. **Get devices into position** - Pick up both devices and hold them still, allowing the data settle to a baseline for at least 30 seconds. Do not make any sudden movements during this time and attempt to hold both devices as still as possible.
1. **Perform the taps** - Quickly and firmly tap the devices against each other 3 times, making contact approximately once per second. The taps need to be strong enough to make a noticeable "spike" in the accelerometer data. The more pronounced and clear the taps are as compared to the baseline data and other noise that may be surrounding the taps, the better the tap detector will be able to identify the taps. **WARNING: While hitting the devices together strongly is important, take care to not damage the devices. For example, tap a connector on one board against the side of another board, avoid hitting chips or other electronics on either board to prevent damage.**
1. **Allow the data to return to baseline again** - Wait for approximately 15-30 seconds to allow the data to settle to a baseline again.
1. **Perform the test** - Return to your testing procedure and complete the actions indicated by the test. The testing procedure will tell you when to return to these instructions.
1. **Repeat Tapping** After you have completed the testing procedure indicated by your test, repeate steps 4 - 6 to append another set of clean taps to the end of your data recording.
1. **End Recording** - End the recording on your devices. Ensure that the data has properly saved and disconnect your devices. The data is now ready for further processing.

## Test Template
Use this template when making a new test to make it easier!

Test Name: [name]  
Test Version: 0.0.0  
Test Purpose: [purpose]  
  
Test Directions:  
\- Complete first part of tapping procedure.  
\- [Other test steps go here]  
\- Complete second part of tapping procedure.