#!/bin/bash
wget https://www.premierleague.com/players
grep -P "/players/[0-9]*/([a-z A-Z]+-?)+/overview" players > results
grep -o "/players/.*/overview" results > output
sed -i 's/\/players/https:\/\/www\.premierleague\.com\/players/' output
touch player_results.csv

sum=$(cat output | wc -l)
echo "Total Players: $sum" >> player_results.csv
while read line;
do
    wget $line
    x=$(grep -i -c "midfielder" overview)
    if [[ $x -gt 0 ]]; then 
        echo "$line, midfielder, $x" >> player_results.csv
    fi
    rm overview
done < output