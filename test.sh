#!/bin/bash
ARG=""
I=1

while [ $I -le $1 ]
do
	ARG+="$RANDOM "
	let "I+=1"
done

echo $ARG
RESULT=$(./push_swap $ARG)
echo "$RESULT" > result
echo "$RESULT" | wc -l
echo "$RESULT" | ./checker $ARG
