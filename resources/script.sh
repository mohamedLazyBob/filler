# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoures <afoures@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/05 14:26:10 by afoures           #+#    #+#              #
#    Updated: 2020/01/09 03:24:32 by mzaboub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

player1="abanlin.filler"
player2="carli.filler"
player3="champely.filler"
player4="grati.filler"
player5="hcao.filler"
player6="superjeannot.filler"

yourplayer="mzaboub.filler"

exec 1> /dev/null

testp1()
{
	p1="0";
	p2="0";
	for value in {1..5}
	do
		./filler_vm -f maps/${1} -p1 players/${2} -p2 players/${3}
		result=$(cat filler.trace | grep won)
		if echo "$result" | grep -q "${2}"
		then
			p1=$(($p1 + 1))
		else
			p2=$(($p2 + 1))
		fi
	done

	echo "${2} vs ${3} | ${1}" >> script.out;
	echo " player 1 : $p1 wins" >> script.out;
	echo " player 2 : $p2 wins" >> script.out;
	echo "" >> script.out;
}

touch script.out
echo "--- new script ---" >> script.out

testp1 map00 $yourplayer $player1
testp1 map00 $player1 $yourplayer 
testp1 map01 $yourplayer $player1
testp1 map01 $player1 $yourplayer 
testp1 map02 $yourplayer $player1
testp1 map02 $player1 $yourplayer 

testp1 map00 $yourplayer $player2
testp1 map00 $player2 $yourplayer 
testp1 map01 $yourplayer $player2
testp1 map01 $player2 $yourplayer 
testp1 map02 $yourplayer $player2
testp1 map02 $player2 $yourplayer 

testp1 map00 $yourplayer $player3
testp1 map00 $player3 $yourplayer 
testp1 map01 $yourplayer $player3
testp1 map01 $player3 $yourplayer 
testp1 map02 $yourplayer $player3
testp1 map02 $player3 $yourplayer 

testp1 map00 $yourplayer $player4
testp1 map00 $player4 $yourplayer 
testp1 map01 $yourplayer $player4
testp1 map01 $player4 $yourplayer 
testp1 map02 $yourplayer $player4
testp1 map02 $player4 $yourplayer 

testp1 map00 $yourplayer $player5
testp1 map00 $player5 $yourplayer 
testp1 map01 $yourplayer $player5
testp1 map01 $player5 $yourplayer 
testp1 map02 $yourplayer $player5
testp1 map02 $player5 $yourplayer 

testp1 map00 $yourplayer $player6
testp1 map00 $player6 $yourplayer 
testp1 map01 $yourplayer $player6
testp1 map01 $player6 $yourplayer
testp1 map02 $yourplayer $player6
testp1 map02 $player6 $yourplayer
