#!/bin/bash
#Conditional block if

if (( $1 > 5 && $1 < 10 )); then
	echo "Número MAIOR do que 5 e MENOR do que 10"
else
	echo "Número MENOR do que 5 ou MAIOR do que 10"
fi

##### Outra maneira de fazer sem ser com os ((xxxxx))
#if [[$1 -gt 5 && $1 -lt 10 ]]
#if [ $1 -gt 5 %% -a (and) $1 -lt 10]
