# sit-stand-noisy_v1.0.0
Procedure for recording labeled sit-to-stand and stand-to-sit transitions with intentional movement noise injected during seated and standing periods. This test is designed to simulate realistic edge cases and evaluate robustness against false positives.

## Requirements
- Phone with IMU (accelerometer + gyroscope) — see [phone-imu_v0.0.0](../device-protocols/phone-imu_v0.0.0.md)
- Stopwatch or annotation tool
- Standard chair
- Flat ground

## Global Constants
- **Phone Placement:** Front pants pocket, camera facing inward toward the leg, camera end pointing toward the bottom of the pocket
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
1. Start IMU recording.
2. Place phone on a table — remain still for at least **10 seconds** to establish a still baseline.
3. Pick up phone and insert into pocket (correct orientation) while standing.
4. Stand still for at least **10 seconds** to establish an on-body baseline.
5. Follow the sequence below, varying the noise type each cycle. Each sit and stand transition should be normal pace (~1.5 seconds). Remain in each position for at least **10 seconds**, performing noise movements naturally during stable periods:

| Cycle | Noise while sitting | Noise while standing |
|---|---|---|
| 1 | Lean forward/backward, reposition | Shift weight, bend forward |
| 2 | Reposition, leg jitter | Bend forward, rotate in place |
| 3 | Leg jitter, partial stand attempts | Shift weight, rotate in place |
| 4 | Lean sideways, partial stand attempts | All standing noise types |

6. Remain standing for at least **10 seconds** after the final transition.
7. Stop recording.
8. Annotate the dataset following the [annotation procedure](../utility-protocols/annotation-procedure_v0.0.0.md).

## Expected Annotations
Label all transitions (`sit_to_stand`, `stand_to_sit`) and stable periods (`sit`, `stand`). Do **not** label individual noise movements as separate states — noise occurs within a `sit` or `stand` interval and should be noted in the dataset description field of the annotation JSON rather than as separate labeled states.
