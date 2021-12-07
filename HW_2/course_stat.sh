#!/bin/bash


num=$@
x=$( echo $num | wc -m )
if [[ $x -ne 7 ]]; then
echo "Wrong number of arguments" 2> stderr
exit
fi

[[ ! -f $num.txt ]] && echo "Course not found" 2> stderr && exit

[[ -d "$num"_stat ]] && rm -r "$num"_stat
mkdir "$num"_stat
touch grades
touch course_statistics
chmod +r grades
chmod +w grades
chmod +x grades


while read id grade; do
echo $grade >> grades
done < $num.txt
sed -i 1d grades
mv ./grades ./"$num"_stat
chmod +r course_statistics
chmod +w course_statistics
chmod +x course_statistics



gcc -g -Wall calc_statistics.c -o prog.exe 	    
./prog.exe ./${num}_stat/grades ./${num}_stat/course_statistics
cat ./${num}_stat/course_statistics
