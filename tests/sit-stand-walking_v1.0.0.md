# sit-stand-walking_v1.0.0
Procedure for recording labeled sit-to-stand and stand-to-sit transitions interspersed with walking segments. This test is designed to introduce realistic false positives from walking activity.

## Requirements
- Phone with IMU (accelerometer + gyroscope) — see [phone-imu_v0.0.0](../device-protocols/phone-imu_v0.0.0.md)
- Stopwatch or annotation tool
- Standard chair
- Flat ground with enough space to walk ~5–10 steps

## Global Constants
- **Phone Placement:** Front pants pocket, camera facing inward toward the leg, camera end pointing toward the bottom of the pocket
- **Environment:** Quiet, flat ground, minimal external disturbances

## Instructions
1. Start IMU recording.
2. Place phone on a table — remain still for at least **10 seconds** to establish a still baseline.
3. Pick up phone and insert into pocket (correct orientation) while standing.
4. Stand still for at least **10 seconds** to establish an on-body baseline.
5. Follow the sequence below, repeating it at least **4 times** to capture statistical variation:
   - Sit down (~1.5s), remain seated for at least **10 seconds**.
   - Stand up (~1.5s), remain standing briefly.
   - Walk at a normal pace for ~5 seconds.
   - Stop and stand still briefly.
6. Remain standing for at least **10 seconds** after the final cycle.
7. Stop recording.
8. Annotate the dataset following the [annotation procedure](../utility-protocols/annotation-procedure_v0.0.0.md).

## Expected Annotations
Label all six activity types: `sit`, `stand`, `sit_to_stand`, `stand_to_sit`, and `walk`. Walking segments should be clearly labeled so that they can be distinguished from sit/stand transitions during algorithm evaluation.
