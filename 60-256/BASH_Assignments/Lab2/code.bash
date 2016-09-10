#!/bin/bash
file=$1
w1=$2
w2=$3
line1=`more $file | grep -w -n $w1 | cut -d ':' -f 1 | head -1`

search=`wc -l $file | cut -c1` 
search=`expr $search - $line1`
line2=`tail -n $search $file | grep -w -n $w2 | cut -d ':' -f 1 | head -1`


if [ -z $line2 ]
   then 
     echo word $w1 appears before word $w2
else
	line2=`expr $line2 + $line1`
	c=`expr $line2 - $line1 + 1`
	head -n $line2 $file | tail -n $c
fi

