#!/bin/bash

function numeric_to_string()
{

	case "$1" in 
		1)
			echo "Um"
			;;
		2)
                        echo "Dois"
                        ;;
		3)
                        echo "Três"
                        ;;
		*)
                        echo "Outro numero"
                        ;;
	esac
	return $1	

}

numeric_to_string $1
