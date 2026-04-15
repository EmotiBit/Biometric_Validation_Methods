# Annotation Procedure
The annotation procedure describes how to label activity intervals in a dataset so that algorithm outputs can be evaluated against ground truth.

## Requirements
- A completed recording session with known transition timings (use a stopwatch during recording, or use post-hoc review of the IMU data)
- A text editor or JSON editor

## Output Format
Each dataset must be accompanied by a JSON annotation file with the following structure:

```json
{
  "description": "Brief description of the dataset, including scenario and notable conditions",
  "states": [
    {
      "label": "<activity_label>",
      "start_time": <seconds>,
      "end_time": <seconds>
    }
  ]
}
```

### Example Labels

| Label | Description |
|---|---|
| `sit` | Subject is seated and stable |
| `stand` | Subject is standing and stable |
| `sit_to_stand` | Transition from sitting to standing |
| `stand_to_sit` | Transition from standing to sitting |
| `walk` | Subject is walking |

### Guidelines
- `start_time` and `end_time` are in **seconds** from the start of the recording.
- The annotation does not need to cover the full recording. Unlabeled periods (e.g., phone still on the table) can be omitted.
- For noise injection scenarios (see [sit-stand-noisy_v0.0.0](../tests/sit-stand-noisy_v0.0.0.md)), do **not** create separate labels for noise movements. Instead, describe them in the `description` field.

## Instructions
1. **During recording:** Use a stopwatch to note the start and end times of every transition and activity segment. Write these down immediately.
2. **After recording:** Create a new `.json` file named to match the dataset (e.g., `sit-stand-baseline_v0.0.0_annotations.json`).
3. **Fill in the `description` field** with a brief summary of the session, including the scenario name, subject conditions, and any notable deviations from the procedure.
4. **Add a state entry for each labeled interval** in chronological order. Use the timings recorded in step 1.
5. **Review** the annotation file to confirm:
   - All states are labeled
   - Times are in seconds and match the recording
   - No overlapping intervals exist
6. **Include the annotation file** in the dataset `.zip` archive alongside the IMU data.

## Example

```json
{
  "description": "Baseline sit-stand dataset, normal pace, minimal noise",
  "states": [
    {
      "label": "stand",
      "start_time": 10.0,
      "end_time": 15.0
    },
    {
      "label": "stand_to_sit",
      "start_time": 15.0,
      "end_time": 16.5
    },
    {
      "label": "sit",
      "start_time": 16.5,
      "end_time": 30.0
    },
    {
      "label": "sit_to_stand",
      "start_time": 30.0,
      "end_time": 31.5
    },
    {
      "label": "stand",
      "start_time": 31.5,
      "end_time": 45.0
    }
  ]
}
```
