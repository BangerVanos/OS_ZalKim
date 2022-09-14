#!/bin/bash

if [ ! -d "$2" ]; then
	echo "There is no $2 directory!"
	exit 0
else
	files=$(find "$2" -name "*.$3")
	echo "${files}" > "$1"
fi
exit 0
