# sit-stand-baseline_v1.0.0
Procedure for recording labeled sit-to-stand and stand-to-sit transitions under ideal conditions with minimal noise and a normal transition pace.

## Requirements
- Phone with IMU (accelerometer + gyroscope) — see [phone-imu_v0.0.0](../device-protocols/phone-imu_v0.0.0.md)
- Stopwatch or annotation tool
- Standard chair
- Flat ground

## Global Constants
- **Phone Placement:** Front pants pocket, camera facing inward toward the leg, camera end pointing toward the bottom of the pocket
- **Environment:** Quiet, flat ground, minimal external disturbances

## Instructions
1. Start IMU recording.
2. Place phone on a table — remain still for at least **10 seconds** to establish a still baseline.
3. Pick up phone and insert into pocket (correct orientation) while standing.
4. Stand still for at least **10 seconds** to establish an on-body baseline.
5. Sit down, aiming to move from standing to sitting in a ~1.5 second period.
6. Remain seated for at least **10 seconds** to establish a seated on-body baseline.
7. Stand up, aiming to move from sitting to standing in a ~1.5 second period.
8. Repeat steps 5–7 at least **3 more times** to capture statistical variation.
9. Remain standing for at least **10 seconds**.
10. Stop recording.
11. Annotate the dataset following the [annotation procedure](../utility-protocols/annotation-procedure_v0.0.0.md).

## Expected Annotations
Each sit-to-stand or stand-to-sit transition should be labeled with a `sit_to_stand` or `stand_to_sit` interval (~1.5 seconds). Stable periods between transitions should be labeled `sit` or `stand`.

**Note:** Transition pace should be normal (~1–2 seconds). Keep movement minimal outside of transitions.
