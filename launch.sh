if [ $# -eq 0 ]; then
	echo "Not enough arguemnts"
else
	make
	ARGS=$(ruby -e "puts (0...$1).to_a.shuffle.sample($1).join(' ')")
	./push_swap $ARGS #| ./checker $ARGS
fi
