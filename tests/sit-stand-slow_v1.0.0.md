# sit-stand-slow_v1.0.0
Procedure for recording labeled sit-to-stand and stand-to-sit transitions with deliberately slow, gradual movement. This test is designed to capture failure cases where transitions are not abrupt.

## Requirements
- Phone with IMU (accelerometer + gyroscope) — see [phone-imu_v0.0.0](../device-protocols/phone-imu_v0.0.0.md)
- Stopwatch or annotation tool
- Standard chair
- Flat ground

## Global Constants
- **Recording Duration:** 135 seconds
- **Phone Placement:** Front pants pocket, camera facing inward toward the leg, phone oriented toward the bottom of the pocket
- **Environment:** Quiet, flat ground, minimal external disturbances

## Instructions
1. Start IMU recording (100 Hz).
2. Place phone on a table — remain still for the first **10 seconds**.
3. At ~10s: pick up phone and insert into pocket (correct orientation) while standing.
4. Stand still until **15 seconds**.
5. At 15s: slowly sit down (~5 seconds), then remain seated.
6. At 30s: slowly stand up (~5 seconds), then remain standing.
7. Repeat steps 5–6 at:
   - (45s, 60s)
   - (75s, 90s)
   - (105s, 120s)
8. Stop recording at 135 seconds.
9. Annotate the dataset following the [annotation procedure](../utility-protocols/annotation-procedure_v0.0.0.md).

## Expected Annotations
Each transition interval should be ~5 seconds. Ensure smooth, gradual movement with no abrupt changes throughout each transition.

**Note:** The timing structure is identical to [sit-stand-baseline_v1.0.0](./sit-stand-baseline_v1.0.0.md). The only difference is transition pace (~5 seconds instead of ~1.5 seconds).
