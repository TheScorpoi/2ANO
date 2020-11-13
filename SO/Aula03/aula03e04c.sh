#!/bin/bash
#Este script valida os argumentos

echo "... Checking ..."

#primeiro verifica se foram introduzidos 2 argumentos

if [[ $# -ne 2 ]]; then #ou ent (($# != 2))

	case $# in
		[0-1]*)
			echo "Foram introduzidos menos de 2 args!"
		;;
		[3-]*)
			echo "Foram introduzidos mais que 2 args!"
		;;
	esac
	exit 1
fi

#código de validação do 1º arg
case $1 in
	[0-99]*) 
		echo "O primeiro arg é um numero 0-99"
		;;
	*)
		echo "O primeiro arg não é um número 0-99"
		;;

esac

#código validação 2º arg
case $2 in
	sec*)
		echo "O segundo arg começa por 'sec'!"
		;;
	*)
		echo "O segundo arg não começa por 'sec'!"
		;;
esac

echo "-----------------FINISH---------------"
