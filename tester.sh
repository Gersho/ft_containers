#!/bin/bash
rm -rf logs
mkdir -p logs
echo -e "\e[33mMaking\e[0m"
make -s fclean
make -s all
make -s clean
make -s std
make -s clean
echo -e "\e[33mBegin testing\e[0m"
echo "Running ft: ./containers > logs/ft.out 2> logs/ft.err"
./containers > logs/ft.out 2> logs/ft.err
echo "Running std: ./containers_std > logs/std.out 2> logs/std.err"
./containers_std > logs/std.out 2> logs/std.err
diff logs/ft.out logs/std.out > logs/diff.out
diff logs/ft.err logs/std.err > logs/diff.err
echo -e "\e[33mEnd testing\e[0m"
noqt=$(($(wc -l < logs/diff.out)))
errqt=$(($(wc -l < logs/diff.err)))
echo -e "\e[33mwc -l diff of standard output: $noqt\e[0m"
echo -e "\e[33mwc -l diff of error    output: $errqt\e[0m"
if [ $noqt -eq 0 ] && [ $errqt -eq 0 ];
then
	echo -e "\e[32mWell done !\e[0m"
else
	echo -e "\e[31mGet back to work !\e[0m"
fi
echo -e "\e[33mTime spent:\e[0m"
pr -mt logs/ft.time logs/std.time
echo -e "\e[33mMemory Check:\e[0m"
valgrind -s --log-file="logs/ft.val" ./containers > logs/ft.out 2> logs/ft.err
valgrind -s --log-file="logs/std.val" ./containers_std > logs/std.out 2> logs/std.err
ftval=$(($(wc -l < logs/ft.val)))
stdval=$(($(wc -l < logs/std.val)))
if [ $ftval -eq $stdval ]
then
	echo -e "\e[32mMemory Check OK !\e[0m"
else
	echo -e "\e[31mERROR ! cat logs/ft.val for more info.\e[0m"
fi
make -s fclean