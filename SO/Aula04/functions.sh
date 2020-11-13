#!/bin/bash

#função para imprimir uma msg de texto
function imprime_msg()
{
	echo "A minha primeira função"
	return 0
}

#função para imprimir a data atual (Ver como formatar esse tipo de data)
function imprime_data()
{
	echo $(date)
	return 0
}

#função para imprimir o hostname
function imprime_hostName()
{
	echo $(hostname)
	return 0
}

#função para imprimir o nome do user, também dá com $USER onde tem o $(who)
function imprime_User()
{
	echo $(whoami)
	return 0
}

