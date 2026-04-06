# sit-stand-walking_v1.0.0
Procedure for recording labeled sit-to-stand and stand-to-sit transitions interspersed with walking segments. This test is designed to introduce realistic false positives from walking activity.

## Requirements
- Phone with IMU (accelerometer + gyroscope) — see [phone-imu_v0.0.0](../device-protocols/phone-imu_v0.0.0.md)
- Stopwatch or annotation tool
- Standard chair
- Flat ground with enough space to walk ~5–10 steps

## Global Constants
- **Recording Duration:** 135 seconds
- **Phone Placement:** Front pants pocket, camera facing inward toward the leg, phone oriented toward the bottom of the pocket
- **Environment:** Quiet, flat ground, minimal external disturbances

## Instructions
1. Start IMU recording (100 Hz).
2. Place phone on a table — remain still for the first **10 seconds**.
3. At ~10s: pick up phone and insert into pocket (correct orientation) while standing.
4. Stand still until **15 seconds**.
5. Follow the sequence below, repeating it 4 times across the recording:

| Time (1st cycle) | Action |
|---|---|
| 15s | Sit down (~1.5s), remain seated |
| 30s | Stand up (~1.5s), remain standing |
| 35s | Walk at a normal pace for ~5 seconds |
| 40s | Stop and stand still |

Repeat at:
- (45s, 60s, 65s, 70s)
- (75s, 90s, 95s, 100s)
- (105s, 120s, 125s, 130s)

6. Stop recording at 135 seconds.
7. Annotate the dataset following the [annotation procedure](../utility-protocols/annotation-procedure_v0.0.0.md).

## Expected Annotations
Label all six activity types: `sit`, `stand`, `sit_to_stand`, `stand_to_sit`, and `walk`. Walking segments should be clearly labeled so that they can be distinguished from sit/stand transitions during algorithm evaluation.
