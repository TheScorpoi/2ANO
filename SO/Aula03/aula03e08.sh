#!/bin/bash
#Select structure to creat menus

#NAO SEI OQ É A VARIÁVEL PS3 QUE FALA NA ALINEA A) :(
echo "Opção não válida -- b "
echo "ISTOOOOOOOO NÃAAAAOOOOOO FUNCIIIONNNAAAA E NAO SEI PQ!!!!!"

var=true

while $var; do
	if [[ $@ == "b" ]]; then
		echo "... Terminating ..."
		var=false
	else
		select arg in $@; do
			echo "You picked $arg ($REPLY)."
		done
	fi
done

echo "Finish"


## Código do Dani, nao funciona as well
#select arg in $@; do
#        case $REPLY in
#        [1-$#])
#               echo "You picked $arg ($REPLY)"
#                ;;
#        *)
#                echo "Invalid Op"
#                exit 1
#                ;;
#        esac
#done
