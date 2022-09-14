#!/bin/bash

files=$1

for file in $(find "$files" -type f);
do	
	ls -lh $file | awk '{print "Access rights: "$1, "Size: "$5, "File: "$9}'
done
exit 0