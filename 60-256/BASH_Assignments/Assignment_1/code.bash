#!/bin/bash
file=$1
old=$2
new=$3
count=0
if [ -f $file ] #If its a file
then
	if [ -w $file ] #If its writeable
	then
		if [[ -z `grep $old $file` ]] #Check if search term is in file 
		then
			echo
		else 
			echo
			echo $file
			echo -e "`cat $file`"		
			sed -i s/$old/$new/g $file #Replace old with new
			echo -e "changed into:\n`cat $file`\n"
			count=`expr $count + 1`
		fi
	else
		echo -e "$file\n`cat $file`\nnot changed due to lack of permission"
	fi
else #It is a directory 

	filelist=( `grep -I -R $old $1 | cut -d ":" -f 1` )
	echo
	for file in ${filelist[@]}
	do		
		echo ${file}
		if [ -w ${file} ] #if it is writeable
		then
			echo -e "`cat ${file}`"			
			sed -i s/"$old"/"$new"/g ${file} #Replace old with new
			echo -e "changed into:\n`cat ${file}`\n"
			count=`expr $count + 1`
		else
			echo -e "`cat ${file}`\nnot changed due to lack of permission\n"
		fi
	done
fi
echo "Total number of files changed is $count"
