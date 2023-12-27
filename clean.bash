#!/bin/bash

# Clean .exe, .out, input.txt, and output.txt files
find . -type f \( -name '*.exe' -o -name '*.out' -o -name 'input.txt' -o -name 'output.txt' \) -exec rm -f {} +