#include <Python.h>
#include <opencv2/highgui/highgui.hpp>
#include "pyboostcvconverter/pyboostcvconverter.hpp"

using namespace cv;

void mirror(Mat img) {
    flip(img, img, 1);
}

/* Python wrapper for the mirror() function. */
static PyObject * pyMirror(PyObject *self, PyObject *args) {
    PyObject *ndArray;

    if (!PyArg_ParseTuple(args, "O", &ndArray))
        return NULL;

    Mat mat = pbcvt::fromNDArrayToMat(ndArray);

	mirror(mat);
    
    return pbcvt::fromMatToNDArray(mat);
}

static PyMethodDef HelloWorldMethods[] = {
    {"mirror", pyMirror, METH_VARARGS, "Mirrors an OpenCV image."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef helloWorldModule = {
    PyModuleDef_HEAD_INIT,
    "helloWorld",     /* name of module */
    "",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    HelloWorldMethods
};

PyMODINIT_FUNC PyInit_helloWorld(void) {
    return PyModule_Create(&helloWorldModule);
}