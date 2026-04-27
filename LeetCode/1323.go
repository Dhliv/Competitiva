package main

import (
	"bufio"
	"fmt"
	"os"
)

var rdr *bufio.Reader = bufio.NewReader(os.Stdin)
var wr *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) {
	fmt.Fprintf(wr, f, a...)
}

func scanf(f string, a ...interface{}) {
	fmt.Fscanf(rdr, f, a...)
}

func flush() {
	wr.Flush()
}

func maximum69Number(num int) int {
	pow := 1000
	ori := num

	for i := 0; i < 4; i++ {
		n := num / pow
		if n == 6 {
			return ori + pow*3
		}

		num = num % pow
		pow /= 10
	}

	return ori
}

func main() {
	var n int
	scanf("%d\n", &n)
	defer flush()

	printf("%v\n", maximum69Number(n))
}
