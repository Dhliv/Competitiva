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

func isPowerOfFour(n int) bool {
	if n <= 0 {
		return false
	}

	for n%4 == 0 {
		n /= 4
	}

	return n == 1
}

func main() {
	var n int
	scanf("%d\n", &n)
	defer flush()

	printf("%v\n", isPowerOfFour(n))
}
