# ProjectEulerCpp
Solutions to Project Euler problems in C++

Project Euler folder contains code for console app to run problems

Other folders are DLL builds that contain code for different, specified, problems. 

Note 1-20 also includes 67.

# Rational Number
This is a class being built out to allow storage of numbers in rational number form. This, currently, works fine, but I want to expand to allow the values to be stored using the NBitInt data type. This is all to allow a single problem to work.

# NBitInt data type
This is a class to contain a single integer value stored as a bitset. It can be instantiated with a user specified number of bits. The operations defined are then specified in the class to allow some basic operations to be carried out between the NBitInts and normal ints.


Relies on Windows.h for DLL loading
