# Porting an algorithm from C++ to Python

## Table of Contents
- [Why?](#why?)
- [How it works](#how-it-works)
- [Requirements](#Requirements)

## Why?
The goal of this project is to allow users to take an algorithm written in C++ and translate it into runnable Python code.
This could allow a user to develop C++ code and run it on the EmotiBit's firmware, software, and through Python, hitting three different metrics.

## How it works
- We use pybind11 to create bindings for existing c++ code to a dynamic python library. These bindings get added to `bindings.cpp`
- These bindings essentially define the class/function prototypes, in the pybind11 format. An example of a binding would look like
```c++
PYBIND11_MODULE(EmotiBitPacket, m) {
	py::class_<EmotiBitPacket>(m, "EmotiBitPacket")
		.def(py::init<>());
	m.def("createHeader", &EmotiBitPacket::createHeader);
	m.def("headerToString", &EmotiBitPacket::headerToString);
	//m.def("createPacket", &EmotiBitPacket::createPacket); 
	py::class_<EmotiBitPacket::Header>(m, "Header")
		.def(py::init<>());
}
```
- The pybind11 python library (installed in the virtual environment) performs the mapping from c++ file to a `.pyd` file.
- The flow to go from `.cpp` to `.pyd` looks like
  - Create a `CMakeLists.txt` that lists the pybind module and its dependency on the source file library.
  - Run `cmake` to create build files
  - Build the files created in the previous step to create the `.pyd` file

## Requirements
In order to configure an algorithm for pybind, a new directory name `pybind` should be created under the root directory. This directory will hold all files related to the C++ to Python process.

In addition, [EmotiBit ArduinoFilters](https://github.com/EmotiBit/EmotiBit_ArduinoFilters) must be present in the Arduino libraries folder (from library manager or manual download) so that the ArduinoMock library can be found by CMake.
- It is possible that ArduinoMock will be pulled out of ArduinoFilters in the future to a place such as the `pybind` directory of each algorithm, or into the Arduino libraries directory as its own library

### Setting up Python Virtual Environment
- Open a new command prompt window
- `cd` to the algorithm repository (ex. EmotiBit_Brainflow_SpO2_algorithm)
- `cd` into the new `pybind` directory under the algorithm root folder
- Run the following command `python -m venv venv`
  - This creates a new folder called `venv` containing the virtual Python environment
- Activate the new environment by running the command `.\venv\Scripts\activate.bat`
  - You will see the prompt in the terminal change. It now shows the Python environment in parenthesis.
- Run the following command to install pybind11. `pip install pybind11==2.13.5`

### Modify `bindings.cpp`
- Download `bindings.cpp` from the `pybind_example` directory in this repo
- Copy `bindings.cpp` into the algorithm `pybind` directory
- Open the newly copied `bindings.cpp` in a text editor or IDE
- Create a new binding for each function that should be exposed in the Python module
  - pybind has many options for dealing with pointers, return values, and more. Refer to the [pybind documentation](https://pybind11.readthedocs.io/en/stable/) if a more complicated binding is required.

### Modify `CMakeLists.txt`
- Download `CMakeLists.txt` from the `pybind_example` directory in this repo
- Copy `CMakeLists.txt` into the algorithm `pybind` directory
- Open the newly copied `CMakeLists.txt` in a text editor or IDE
- Update any references to ALGORITHM_NAME with the name of the Algorithm
  - The name put in `project` will also be the name of the Python module
- Under the "Algorithm/pybind11 Setup" header comment, add all required `.cpp` and header directories in the locations designated by the comments

### Build
- Open a terminal window
- `cd` into the `pybind` directory
- Activate the Python virtual environment by running `./venv/Scripts/activate.*` (choose appropriate file extension for terminal)
- Run `cmake -B build` to generate the build files in a subdirectory named `build`
- Run `cmake --build build --config Release` to generate the `.pyd` file in the `pybind/build/Release` directory

## Examples
### [EmotiBit_Brainflow_SpO2_Algorithm](https://github.com/EmotiBit/EmotiBit_Brainflow_SpO2_Algorithm)
- Ensure [EmotiBit ArduinoFilters](https://github.com/EmotiBit/EmotiBit_ArduinoFilters) is present in the `Arduino/libraries` folder
- Clone [EmotiBit_Brainflow_SpO2_Algorithm](https://github.com/EmotiBit/EmotiBit_Brainflow_SpO2_Algorithm) into `Arduino/libraries`
- Follow the instructions [above](#build) on how to build the Python module
- In a new window, navigate to one of the tests under the `tests` directory
- Copy `EmotiBit.csv` into a new folder (location does not matter)
- Run EmotiBit DataParser on the newly copied `EmotiBit.csv` file. This should generate several new `.csv` files in the same directory
- Return to the terminal window where the Python module was built
- Run `python run.py [PATH TO CSV FILES]`
- A plot showing raw PPG and the calculated SpO2 should pop up, and a new file named `generated.csv` should now be in the directory