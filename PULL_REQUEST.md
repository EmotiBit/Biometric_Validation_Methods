# Description

This PR adds the initial set of test procedures, device protocols, and utility protocols for the Biometric Validation Methods repository.

### What this PR provides
- **4 test procedures** covering sit-stand transitions under baseline, slow, noisy, and walking conditions
- **1 device protocol** defining data collection steps for a smartphone IMU
- **1 utility protocol** for dataset annotation
- A standard annotation output format (JSON) with valid activity labels and field definitions

### Key idea
Each file is a self-contained procedure document versioned independently using the `vX.Y.Z` suffix. Tests, device protocols, and utility protocols cross-reference each other where needed (e.g., all sit-stand tests link to `phone-imu_v0.0.0` and `annotation-procedure_v0.0.0`), but remain decoupled so that any document can be updated without invalidating others at the same major version.

# Why this is useful

- Establishes a reproducible, documented baseline for collecting labeled biometric data
- Enables consistent dataset creation across contributors and runs
- Provides clear annotation guidelines so algorithm evaluation is based on a shared ground-truth format
- Covers a range of difficulty levels (baseline → slow → noisy → walking) to stress-test algorithm robustness

# Requirements
N/A

# Issues Referenced
N/A

# Documentation update

- Added [tests/sit-stand-baseline_v1.0.0.md](./tests/sit-stand-baseline_v1.0.0.md) — normal-pace sit-stand transitions under ideal conditions
- Added [tests/sit-stand-slow_v1.0.0.md](./tests/sit-stand-slow_v1.0.0.md) — slow (~5s) transitions to capture gradual-movement failure cases
- Added [tests/sit-stand-noisy_v1.0.0.md](./tests/sit-stand-noisy_v1.0.0.md) — normal-pace transitions with injected noise movements during stable sit/stand periods
- Added [tests/sit-stand-walking_v1.0.0.md](./tests/sit-stand-walking_v1.0.0.md) — transitions interspersed with walking segments to introduce realistic false positives
- Added [device-protocols/phone-imu_v0.0.0.md](./device-protocols/phone-imu_v0.0.0.md) — smartphone IMU setup, placement, and CSV export format (100 Hz, accel + gyro)
- Added [utility-protocols/annotation-procedure_v0.0.0.md](./utility-protocols/annotation-procedure_v0.0.0.md) — JSON annotation format, valid labels, contiguity rules, and step-by-step instructions

# Notes for Reviewer

- All four sit-stand tests share the same timing structure (135s recording, phone placed on table for first 10s, standing from 10–15s, then 4 sit/stand cycles) — only pace and noise injections differ across variants. This makes the baseline a direct reference for the others.
- `sit-stand-noisy` instructs annotators to **not** create separate labels for noise movements; these are described in the `description` field of the annotation JSON. This is explicitly called out in both the test procedure and the annotation procedure.
- `sit-stand-walking` introduces a `walk` label not present in the other sit-stand tests; the annotation procedure's valid labels table already includes `walk` to support this.

# Testing
N/A — all additions are documentation files (`.md`). No code changes were made.

# Checklist to allow merge
- [ ] All cross-references between files resolve correctly (links point to existing documents)
- [ ] Valid label table in `annotation-procedure_v0.0.0.md` covers all labels used across all test procedures
## Documentation
- [ ] Get approval from the reviewer
- [ ] Version suffixes are consistent with the versioning structure defined in `README.md`
