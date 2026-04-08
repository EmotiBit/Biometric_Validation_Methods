# Phone IMU
A smartphone used to record raw IMU data (accelerometer + gyroscope) for sit-stand transition benchmarking.

## Requirements
- Smartphone with accelerometer and gyroscope
- IMU recording app capable of:
  - Recording accelerometer and gyroscope simultaneously
  - Exporting data as CSV with a timestamp column

## Placement
- **Pocket:** Front pants pocket
- **Orientation:** Camera facing inward toward the leg, phone oriented toward the bottom of the pocket (top of phone pointing down)
- **Initialization:** Start recording with the phone on a table, then insert into pocket at ~10 seconds while standing

## Data Collection Instructions
1. Open your IMU recording app and configure:
   - Sensors: **accelerometer** and **gyroscope**
2. Place the phone flat on a table.
3. Begin recording.
4. At ~10 seconds, pick up the phone and insert it into your front pants pocket with the correct orientation (see Placement above).
5. Follow the test procedure.
6. When the procedure is complete, stop recording.
7. Export the recorded data as a CSV file. Ensure the file contains:
   - A timestamp column (in seconds)
   - Accelerometer columns (x, y, z)
   - Gyroscope columns (x, y, z)

## Output Format
The exported CSV should resemble the following structure:

```
timestamp,accel_x,accel_y,accel_z,gyro_x,gyro_y,gyro_z
0.000,0.012,-0.003,9.812,0.001,-0.002,0.000
0.010,0.011,-0.004,9.810,0.001,-0.001,0.000
...
```
