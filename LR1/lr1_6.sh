#!/bin/bash

if gcc "$1" -o "$2"; then
	./"$2"
else
	echo "Error occured during compilation!"
	exit 1
fi
exit 0