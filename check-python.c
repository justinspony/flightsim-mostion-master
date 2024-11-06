#include <Python.h>

int main() {
    PyObject *pModule, *pFunc, *pArgs, *pValue;

    // Initialize the Python interpreter
    Py_Initialize();

    // Load the Python module
    pModule = PyImport_ImportModule("example");

    if (pModule != NULL) {
        // Get reference to the Python function
        pFunc = PyObject_GetAttrString(pModule, "hello_python");

        if (pFunc && PyCallable_Check(pFunc)) {
            // Call the Python function with no arguments
            pValue = PyObject_CallObject(pFunc, NULL);

            if (pValue != NULL) {
                // Output the result of the function call
                printf("Python function returned: ");
                PyUnicode_Print(pValue);
                printf("\n");

                // Clean up
                Py_DECREF(pValue);
            } else {
                // Handle error
                PyErr_Print();
            }
        } else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function 'hello_python'\n");
        }

        // Clean up
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
        fprintf(stderr, "Failed to load Python module 'example'\n");
    }

    // Finalize the Python interpreter
    Py_Finalize();

    return 0;
}
