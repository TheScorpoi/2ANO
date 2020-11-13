#!/bin/bash
# Calculate the sum of a series of numbers

SCORE="0"
SUM="0"
COUNTER="0"
MEDIA="0"

while true; do
	echo -n "Enter your score [0-10]! ('q' to quit): "
	read SCORE;

	if (("$SCORE" < "0" )) || (("$SCORE" > "10")); then
		echo "Put valid numbers"
	#alinea b) fazer a opção de reiniciar a sum, sendo dps também preciso dar reset no counter por causa da media
	elif [[ "$SCORE" == "r" ]]; then
		echo "------Reiniciando a contagem------"
		SUM="0"
		COUNTER="0"

	elif [[ "$SCORE" == "q" ]]; then
		echo "Sum: $SUM"
		break
	else
		SUM=$((SUM + SCORE))
		COUNTER=$((COUNTER + 1))
	fi
done

MEDIA=$((SUM/COUNTER))
echo "Media: $MEDIA"

echo "---- EXITING ----"
