#!/bin/bash
#Conditional block if

if [ "$1" = "$2" ]; then #com [[xxxx]] funciona bem, depois para so funcionar com [xxxx] é preciso por as aspas no $1 $2
	echo "O arg1 é igual ao arg2"
else
	echo "Os args são diferentes"
fi
