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

func largestGoodInteger(num string) string {
	largest := -1

	for i := 0; i < len(num)-2; i++ {
		if num[i] == num[i+1] && num[i] == num[i+2] {
			n := rune(num[i]) - rune('0')
			largest = max(largest, int(n))
		}
	}

	ans := ""
	if largest != -1 {
		for i := 0; i < 3; i++ {
			ans += string(rune(largest) + rune('0'))
		}
	}

	return ans
}

func main() {
	var num string
	scanf("%s\n", &num)
	defer flush()

	printf("%s\n", largestGoodInteger(num))
}
