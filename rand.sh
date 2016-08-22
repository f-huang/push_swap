#!/bin/bash

if [ $# -eq 1 ]; then
	let i=0
	let array=(0)
	while [ $i -lt $1 ];do
		let rand=$RANDOM%1000
		let array[$i]=$rand
		echo -n ${array[$i]}" "
		let i+=1
	done
	echo
else
	echo "usage: ./rand.sh <number>"
	exit
fi
