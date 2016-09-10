#!/bin/bash
fact ()
{
	res=$(( $1 % $2 ))
	if [ $res -eq 0 ]
	then
		echo $2*`fact $(( $1 / $2 )) $2`
	elif test $2 -le $1
	then
		echo `fact $1 $(( $2 + 1))`

	fi

}
if [[ -z $1 || -n $2 ]]
then
	echo Use exactly one argument
else
	rem=`echo $1 | tr -d '[:digit:]'`
	if [ -z "$rem" ]
	then
		echo $1 = `fact $1 2`1 
	else
		echo $1 is not a valid number. Try Again
	fi
fi
