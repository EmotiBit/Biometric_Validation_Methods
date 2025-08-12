#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include "algorithm.h" // Placeholder for actual header file

namespace py = pybind11;

PYBIND11_MODULE(ALGORITHM_NAME, m) { // ALGORITHM_NAME should match the CMakeLists.txt project name
  // Using EmotiBitPacket class and functions as an example
  py::class_<EmotiBitPacket>(m, "EmotiBitPacket")
		.def(py::init<>());
	m.def("createHeader", &EmotiBitPacket::createHeader);
	m.def("headerToString", &EmotiBitPacket::headerToString);
	py::class_<EmotiBitPacket::Header>(m, "Header")
		.def(py::init<>());
}