#!/bin/bash

if [ -f "arguments.txt" ]; then
	rm "arguments.txt"
fi
echo "$@" > "arguments.txt"
for arg in $@; do
	echo "$arg"	
done
exit 0