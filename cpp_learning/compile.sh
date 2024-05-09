#!/bin/bash

# Check if an argument was provided
if [ -z "$1" ]; then
    echo "No argument supplied. Please provide the name of the C++ file (without the .cpp extension)."
    exit 1
fi

# Compile the C++ file
g++ $1.cpp -o $1.o

# Run the executable
./$1.o

# Clean up the object file
rm -f $1.o
