#!/bin/bash

lista=({1..10})

for i in "${lista[@]}"; do
	echo "$i"
done


echo "Isto é um teste"
test1=(33,44,55)
echo -n "test1[1] = "
echo ${test1[1]}
