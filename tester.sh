#!/bin/bash
mkdir -p logs
echo "Making"
make -s fclean
make -s all
make -s clean
make -s std
make -s clean
echo "Begin testing"
echo "Running ft"
./containers > logs/ft.out 2> logs/ft.err
echo "Running std"
./containers_std > logs/std.out 2> logs/std.err
diff logs/ft.out logs/std.out > logs/diff1.out
diff logs/ft.err logs/std.err > logs/diff2.out
echo "End testing"
noqt=$(($(wc -l < logs/diff1.out)))
errqt=$(($(wc -l < logs/diff2.out)))
echo "wc -l diff of standard output: $noqt"
echo "wc -l diff of error    output: $errqt"
if [ $noqt -eq 0 ] && [ $errqt -eq 0 ];
then
	echo -e "\e[32mWell done !\e[0m"
else
	echo -e "\e[31mGet back to work !\e[0m"
fi