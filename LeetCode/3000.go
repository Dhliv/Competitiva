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

func areaOfMaxDiagonal(dimensions [][]int) int {
	longest := 0
	maxArea := 0

	for _, sq := range dimensions {
		diag := sq[0]*sq[0] + sq[1]*sq[1]
		if diag > longest {
			longest = diag
			maxArea = sq[0] * sq[1]
		}

		if diag == longest {
			longest = diag
			a := sq[0] * sq[1]
			maxArea = max(maxArea, a)
		}
	}

	return maxArea
}

func main() {
	var n int
	scanf("%d\n", &n)
	var arr [][]int = make([][]int, n)

	for i := range n {
		arr[i] = make([]int, 2)
		scanf("%d %d\n", &arr[i][0], &arr[i][1])
	}
	defer flush()

	printf("%v\n", areaOfMaxDiagonal(arr))
}
