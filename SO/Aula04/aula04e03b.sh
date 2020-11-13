#!/bin/bash

lista=( $(seq 2 3 15) )

echo vals ${lista[@]}		#para ter acesso a todos os elementos doa array
echo count ${#lista[@]}		#para saber o tamanho do array
echo index ${!lista[@]}		#para saber os indices do array

for ((i = 0; i < ${#lista[@]}; i++)); do
	lista[i]=$((${lista[i]}+1))
	echo "$i: ${lista[i]}"
done
unset lista[1]
unset lista[3]

echo count ${#lista[@]}

for i in ${!lista[@]}; do
	echo "$i: ${lista[i]}"
done
