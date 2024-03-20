#invalid tests
counter=0;
printcolor()
{
	if [ $((counter % 2)) -eq 0 ]; then
		echo -e "\033[1;31mtest $counter : $@\033[0;31m" # print in red
	else
		echo -e "\033[1;37mtest $counter : $@\033[0;37m" # print in blue
	fi
	
}

doall(){
	printcolor $@; doall $@ 2>&1 | grep -e "lost" -e "definitely" -e "indirectly" -e "possibly" -e "still reachable" -e "in use" -e "invalid" -e "uninitialized" -e "errors" -e "warnings" -e "errors from" -e "at exit" -e "at start" -e "at end"
	((counter++))
	echo ""
	read -p "Press enter to continue"
	echo ""
	echo "************************************"
	echo ""
}

doall nope
doall nope nope
doall nope nope nope
doall nope nope nope xxxx; rm xxxx
doall "" nope nope xxxx; rm xxxx
doall test "" nope xxxx; rm xxxx
doall test nope "" xxxx; rm xxxx
doall test nope nope ""

#basic tests
doall infile cat ls outfile


doall infile cat cat cat outfile
doall infile cat ls outfile
doall main.c "ls" "cat" out
doall /dev/stdin cat ls /dev/stdout
doall /dev/stdin cat cat /dev/stdout
doall infile cat ls outfile
doall infile cat ls outfile
doall /dev/stdin cat cat cat ls /dev/stdout
doall /dev/stdin cat cat /dev/stdout
doall /dev/stdin cat cat ls /dev/stdout
doall infile cat ls /dev/stdout
doall infile cat ls out
doall /de/stdin cat ls /dev/stdout
doall infile cat ls ls out
doall infile cat ls out
doall test.sh cat cat cat outfile
doall test.sh cat ls cat outfile
doall test.sh cat ls /dev/stdout
doall test.sh cat ls outfile
doall cat cat 1
doall nope cat cat 1


doallbonus here_doc "" "cat -e" "cat -e" out
doallbonus here_doc s "cat -e" "cat -e" out; cat out
doallbonus here_doc stop "cat -e" "cat -e" out
doallbonus squid squid squid squid
doallbonus here_doc stop cat cat 1
doallbonus here_dosc stop cat cat 1
doallbonus squid1 cat cat
doallbonus squid1 cat cat 1
doallbonus squid squid squid squid
