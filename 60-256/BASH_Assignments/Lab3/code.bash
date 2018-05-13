#!/bin/bash
fdsequence=`ls`
fdarray=( $fdsequence )

echo Part B: shell command and array
echo list all directories and files in current directory: $fdsequence
echo total number of files and directories: ${#fdarray[@]}
echo the first element in this list: ${fdarray[0]}
echo all elments in this list: 
for i in ${fdarray[@]}
do
	echo $i
done
