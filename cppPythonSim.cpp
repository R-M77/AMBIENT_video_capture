#include <iostream>
#include <fstream>
#include <Python.h>

int main() {
    Py_Initialize();

    // Import the pythonSim module
    PyObject* pythonSimModule = PyImport_ImportModule("pythonSim");
    if (!pythonSimModule) {
        std::cerr << "Failed to import pythonSim module" << std::endl;
        return 1;
    }

    // Get the process_signal function from the module
    PyObject* processSignalFunc = PyObject_GetAttrString(pythonSimModule, "process_signal");
    if (!processSignalFunc || !PyCallable_Check(processSignalFunc)) {
        std::cerr << "Failed to get process_signal function from pythonSim module" << std::endl;
        return 1;
    }

    // Call the process_signal function with a signal_value argument
    int signal_value = 42;
    PyObject* arg = Py_BuildValue("(i)", signal_value);
    PyObject* result = PyObject_CallObject(processSignalFunc, arg);
    Py_DECREF(arg);
    if (!result) {
        std::cerr << "Failed to call process_signal function" << std::endl;
        return 1;
    }

    // Get the result value from the function and print it
    char* result_str;
    PyArg_Parse(result, "s", &result_str);
    std::cout << result_str << std::endl;
    Py_DECREF(result);

    // Create a new text file and write a message to it
    std::ofstream file("result.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to create result.txt file" << std::endl;
        return 1;
    }
    file << "The signal value is: " << signal_value << std::endl;
    file.close();

    // Clean up
    Py_DECREF(processSignalFunc);
    Py_DECREF(pythonSimModule);
    Py_Finalize();
    return 0;
}
