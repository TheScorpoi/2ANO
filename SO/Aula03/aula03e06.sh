#!/bin/bash
# This script opens 4 terminal windows

#Didnt work...i dont know where is the error...

i="0"
while [[ $i -lt 4 ]]; do
	xterm -e &
	i=$(($i + 1))
done;

## alinea 6 c)

i="0"

until [[ $i -e 4 ]]; do
	xterm &
	i=$(($i+1))
done;
