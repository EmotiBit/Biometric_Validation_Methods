# Phone IMU
A smartphone used to record raw IMU data (accelerometer + gyroscope) for sit-stand transition benchmarking.

## Requirements
- Smartphone with accelerometer and gyroscope
- IMU recording app capable of:
  - Recording accelerometer and gyroscope simultaneously
  - Exporting data as CSV with a timestamp column

## Output Format
The exported CSV should resemble the following structure:

```
timestamp,accel_x,accel_y,accel_z,gyro_x,gyro_y,gyro_z
0.000,0.012,-0.003,9.812,0.001,-0.002,0.000
0.010,0.011,-0.004,9.810,0.001,-0.001,0.000
...
```
