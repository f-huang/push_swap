#!/bin/bash

if [ $# -eq 1 ]; then
	let i=0
	let array=(0)
	while [ $i -lt $1 ];do
		let rand=$RANDOM%1000
		let dup=0
		let j=0
		if [ $i -gt 0 ]; then
			while [ $j -lt $i ]; do
				if [ ${array[$j]} -eq $rand ]; then
					let i-=1
					dup=1
				fi
				let j+=1
			done
		fi
		if [ $dup -eq 0 ];then
			let array[$i]=$rand
			echo -n ${array[$i]}" "
		fi
		let i+=1
	done
	echo
else
	echo "usage: ./rand.sh <number>"
	exit
fi
