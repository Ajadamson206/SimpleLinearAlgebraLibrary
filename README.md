# SimpleLinearAlgebraLibrary

A generic linear algebra library

To create the dll run the python script "generateLibrary.py"
This will create the linalg.h libLinAlg.so files.

To use the files make sure to link the .so file by adding

-L /path/to/files/ -lLinAlg

to your makefile or compiler call.

Dont forget to add the location of the .so file to the LD_LIBRARY_PATH environment variable

export LD_LIBRARY_PATH="/path/to/build/"