#!/bin/bash

# Check if an argument was provided
if [ -z "$1" ]; then
    echo "No argument supplied. Please provide the name of the C++ file (without the .cpp extension)."
    exit 1
fi

filename="${1%.cpp}"

# Compile the C++ file
g++ "${filename}.cpp" -o "${filename}.o"

# Run the executable
./"${filename}.o"

# Clean up the object file
rm -f "${filename}.o"
