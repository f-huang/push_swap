#!/bin/bash

if [ $# -ne 1 ]; then
	echo "usage: ./go.sh <number>";
	exit;
fi

ARGS=$(../../rand.sh $1);
echo $ARGS
./push_swap $ARGS;
./push_swap $ARGS | wc -l

