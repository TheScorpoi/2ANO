#!/bin/bash
#Este script tem implementado um algoritmo de ordenação por seleção
##
## Depois fazer isto a ir buscar os valores a um ficheiro.txt
## cat file.txt
## 20
## 30
## ....
## $lista($(cat file.txt))
##

echo "Introduza o tamanho do array: "
read n
echo "Introduza os numeros para por no array: "

for((i=0; i<n; i++))
do
	read lista[$i]
done

## -----------------------------------------------------------------------------
## -------------------------- Algoritmo de ordenação ---------------------------
## -----------------------------------------------------------------------------
## O algoritmo é composto por 2 ciclos for, no primeiro vai buscar o primeiro
## elemento do array e guarda-o como menor e guarda também o seu indice.
## No segundo vai comparar a variável menor com os outros elementos do array
## pondo o o elemento menor no primeiro indice (isso é feito na parte de código
## das da variável temporária...
## Volta-se a repetir todo o processo começando sempre com o menor num elemento
## i+1 do que o anterior
## -----------------------------------------------------------------------------

for((i=0; i<n-1; i++)); do
	menor=${lista[$i]} 	#guardar na varável menor o elemento com o indice i
	indice=$i 		#guardar o indice do argumento de menor
	for((j=i+1; j<n; j++));do
		if ((lista[j]<menor)); then	#se o arg seguinte de i (i+1) for < do que
			menor=${lista[$j]}	#o menor que está na variável, esse fica
			indice=$j		#como o novo menor, e atualiza-se o seu indice
		fi
	done

	temp=${lista[$i]}		#na variável temporária colocamos o valor menor
	lista[$i]=${lista[$indice]}	#mudamos os indices
	lista[$indice]=$temp		#colocamos no indice correto o elemento menor 
done

# Printar array
echo "Array Ordenado: "
echo ${lista[@]}
