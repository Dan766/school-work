#!/bin/bash
echo -n "Enter a value>"
read a
echo -n "Enter another value>"
read b
sum=$(($a+$b))
echo "The sum $a + $b is $sum"
difference=$(($a-$b))
echo "The difference $a-$b is $difference"
product=$(( $a * $b ))
echo "The product of $a and $b is $product"
if [[ $b -ne 0 ]]; then
    quotient=$(($a/$b))
    echo "The division $a/$b is $quotient"
else
    echo "The division is impossible"
fi
