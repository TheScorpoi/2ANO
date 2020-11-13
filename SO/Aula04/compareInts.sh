#!/bin/bash


function compareints() {

if (( $1 > $2 )); then
	return 1
elif (( $1 < $2 )); then
	return 2 
else
	return 0
fi
}


echo "Escreva 2 números separados por espaços: "
read n1
read n2

compareints $n1 $n2

case $? in
	0)
	echo "$n1 = $n2"
	;;
	1)
	echo "$n1 > $n2"
	;;
	2)
	echo "$n1 < $n2"
	;;
esac
 
