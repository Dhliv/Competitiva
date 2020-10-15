for input in secret/*.in; do
    output="${input%.in}.ans"
    echo "$input $output"
    ./a.out < "$input" > "$output"
done
