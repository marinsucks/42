if [ -z "$(grep ARG$1="\$(cat $PWD/tests/$1.txt)" ~/.zshrc)" ]; then
	echo "ARG$1=\$(cat $PWD/tests/$1.txt)" >> ~/.zshrc
fi