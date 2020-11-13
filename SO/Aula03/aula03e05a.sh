#!/bin/bash
#For all the files in a folder, show their properties

#código para o validação de argumentos
if (( $# != 1)); then
	echo "Nº de args inválidos!"
	exit 1
else
	if [ -d $1 ]; then 	#acho que para só passarem diretorias temos de por -d neste if
		for f in $1/*; do
			file "$f"
			extension="${f##*.}"
			filename="${f%.*}"
			mv "$f" "${filename}.${extension}"
		done
	else
		echo "O arg passado não é  uma diretoria!"
	fi
fi
echo "FINISHED"
