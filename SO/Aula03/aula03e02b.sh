#!/bin/bash
#Conditional block if

if [[ $1 = $2 ]]; then
	echo "O arg1 é igual ao arg2"
else
	echo "Os args são diferentes"
fi
