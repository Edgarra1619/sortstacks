#!/bin/bash
ARG=""
I=1

while [ $I -le $1 ]
do
	ARG+="$RANDOM "
	let "I+=1"
done

echo $ARG
rm -fr result
./push_swap $ARG > result
wc -l < result
./checker $ARG < result
