while true; do
    ./data $RANDOM > data.in
    ./prog < data.in > progout.out
    ./std < data.in > stdout.out
    diff progout.out stdout.out
	if [ $? -ne 0 ]; then break; fi
done

