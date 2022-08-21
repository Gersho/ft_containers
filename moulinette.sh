#!/bin/bash
rm -rf logs
mkdir -p logs
echo -e "\033[33mMaking\033[0m"
make -s fclean
make -s all
make -s clean
make -s std
make -s clean
echo -e "\033[33mBegin testing\033[0m"
echo "Running ft: ./containers > logs/ft.out 2> logs/ft.err"
./containers > logs/ft.out 2> logs/ft.err
echo "Running std: ./containers_std > logs/std.out 2> logs/std.err"
./containers_std > logs/std.out 2> logs/std.err
diff logs/ft.out logs/std.out > logs/diff.out
diff logs/ft.err logs/std.err > logs/diff.err
echo -e "\033[33mEnd testing\033[0m"
noqt=$(($(wc -l < logs/diff.out)))
errqt=$(($(wc -l < logs/diff.err)))
echo -n "wc -l diff of standard output: "
if [ $noqt -eq 0 ]
then
	echo -e "\033[32m$noqt\033[0m"
else
	echo -e "\033[31m$noqt\033[0m"
fi
echo -n "wc -l diff of error    output: "
if [ $errqt -eq 0 ]
then
	echo -e "\033[32m$errqt\033[0m"
else
	echo -e "\033[31m$errqt\033[0m"
fi
if [ $noqt -eq 0 ] && [ $errqt -eq 0 ];
then
	echo -e "\033[32mWell done !\033[0m"
else
	echo -e "\033[31mGet back to work !\033[0m"
fi
echo -e "\033[33mTime spent:\033[0m"
pr -mt logs/ft.time logs/std.time

if command -v valgrind &> /dev/null
then
	echo -e "\033[33mMemory Check with valgrind:\033[0m"
	valgrind -s --log-file="logs/ft.val" ./containers > /dev/null 2> /dev/null
	valgrind -s --log-file="logs/std.val" ./containers_std > /dev/null 2> /dev/null
	ftval=$(($(wc -l < logs/ft.val)))
	stdval=$(($(wc -l < logs/std.val)))
	if [ $ftval -eq $stdval ]
	then
		echo -e "\033[32mMemory Check OK !\033[0m"
	else
		echo -e "\033[31mERROR ! cat logs/ft.val for more info.\033[0m"
	fi
elif command -v leaks &> /dev/null
then
	echo -e "\033[33mMemory Check with leaks -atExit:\033[0m"
	leaks -atExit -- ./containers > /dev/null 2> /dev/null
	if [ $? -eq 0 ]
	then
		echo -e "\033[32mMemory Check OK !\033[0m"
	else
		echo -e "\033[31mERROR ! \`leaks -atExit -- ./containers\` for more info.\033[0m"
	fi	
else
	echo "Unable to Test Memory"
fi