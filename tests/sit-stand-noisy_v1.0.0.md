# sit-stand-noisy_v1.0.0
Procedure for recording labeled sit-to-stand and stand-to-sit transitions with intentional movement noise injected during seated and standing periods. This test is designed to simulate realistic edge cases and evaluate robustness against false positives.

## Requirements
- Phone with IMU (accelerometer + gyroscope) — see [phone-imu_v0.0.0](../device-protocols/phone-imu_v0.0.0.md)
- Stopwatch or annotation tool
- Standard chair
- Flat ground

## Global Constants
- **Recording Duration:** 135 seconds
- **Phone Placement:** Front pants pocket, camera facing inward toward the leg, phone oriented toward the bottom of the pocket
- **Environment:** Quiet, flat ground, minimal external disturbances

## Noise Types

**While Sitting:**
- Lean forward/backward
- Reposition in chair
- Leg jitter
- Partial stand attempts (begin to rise, then sit back down)
- Lean sideways

**While Standing:**
- Shift weight between feet
- Bend forward
- Rotate/turn in place

## Instructions
1. Start IMU recording (100 Hz).
2. Place phone on a table — remain still for the first **10 seconds**.
3. At ~10s: pick up phone and insert into pocket (correct orientation) while standing.
4. Stand still until **15 seconds**.
5. Follow the sequence below, varying the noise type each cycle:

| Cycle | Sit at | Noise while sitting | Stand at | Noise while standing |
|---|---|---|---|---|
| 1 | 15s | Lean forward/backward, reposition | 30s | Shift weight, bend forward |
| 2 | 45s | Reposition, leg jitter | 60s | Bend forward, rotate in place |
| 3 | 75s | Leg jitter, partial stand attempts | 90s | Shift weight, rotate in place |
| 4 | 105s | Lean sideways, partial stand attempts | 120s | All standing noise types |

- Each sit and stand transition should be normal pace (~1.5 seconds).
- Perform noise movements naturally during the stable sit/stand periods between transitions.

6. Stop recording at 135 seconds.
7. Annotate the dataset following the [annotation procedure](../utility-protocols/annotation-procedure_v0.0.0.md).

## Expected Annotations
Label all transitions (`sit_to_stand`, `stand_to_sit`) and stable periods (`sit`, `stand`). Do **not** label individual noise movements as separate states — noise occurs within a `sit` or `stand` interval and should be noted in the dataset description field of the annotation JSON rather than as separate labeled states.
