#!/bin/bash
set -e

make addition

file=$1
#echo "$file"
#file=append.dat
echo "---- list or create file ----"
if [[ -f $file ]]
then
	echo "the db file: $file has already existed"
	valgrind -q ./addition $file l
else
	echo "file $file not existed, create first"
	valgrind -q ./addition $file c 50 20
fi

echo "---- set database address ----"
valgrind -q ./addition $file s 0 Jonathan 	Jonathan@Joestar 		Male
valgrind -q ./addition $file s 1 Dio 	  	Dio@Brando 				Male
valgrind -q ./addition $file s 2 Lisa     	Lisa@Lisa 				Female
valgrind -q ./addition $file s 3 Suzi		Suzi@Q	 				Female
valgrind -q ./addition $file s 4 Polnareff 	Jean@PierrePolnareff 	Male
valgrind -q ./addition $file s 5 Jotaro 	Jotaro@Kujo	 			Male
valgrind -q ./addition $file s 6 Kakyoin 	Noriaki@Kakyoin	 		Male
valgrind -q ./addition $file s 7 Holy   	Holy@Kojo	 			Female

echo "---- list and get some database ----"
valgrind -q ./addition $file l
valgrind -q ./addition $file g 6
valgrind -q ./addition $file g 2

echo "---- delete database ----"
valgrind -q ./addition $file d 4
valgrind -q ./addition $file l

echo "---- find test ----"
valgrind -q ./addition $file f name Dio
valgrind -q ./addition $file f gender Female

echo "---- v test ----"
valgrind -q ./addition $file v

echo "---- error test ----"
valgrind -q ./additon l
