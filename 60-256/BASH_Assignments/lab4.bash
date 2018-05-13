#!/bin/bash
courses="courses.txt"
emails="emails.txt"
if [ -z $1 ]; then
	echo usage: lab4 course-number
	exit
fi

IDs=( `grep -w $1 $courses | cut -d " " -f 1` )

if [[ -z `echo ${IDs[@]}` ]]; then
	echo course number $1 not found
fi

for i in ${IDs[@]}
do
	echo `grep -w $i $emails | cut -d " " -f 2`
done
