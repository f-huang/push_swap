if [ $# -eq 0 ]; then
	echo "Not enough arguemnts"
else
	FILENAME="result"
	# make
	ARGS=$(ruby -e "puts (-$1...$1).to_a.shuffle.sample($1).join(' ')")
	TOTAL=$(./push_swap $ARGS > $FILENAME | wc -l)
	cat $FILENAME | ./checker $ARGS
	print "Total = $TOTAL"
fi
