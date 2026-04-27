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

func minimumArea(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	lx, ux, ly, uy := n, 0, m, 0
	hasOne := false

	for i := range n {
		for j := range m {
			if grid[i][j] == 0 {
				continue
			}

			hasOne = true
			lx, ux = min(lx, i), max(ux, i)
			ly, uy = min(ly, j), max(uy, j)
		}
	}

	if !hasOne {
		return 0
	}

	return (ux - lx + 1) * (uy - ly + 1)
}

func main() {
	var n, m int
	scanf("%d %d\n", &n, &m)
	var mtx [][]int = make([][]int, n)

	for j := range n {
		arr := make([]int, m)
		for i := range m {
			if i == 0 {
				scanf("%d", &arr[i])
			} else if i == m-1 {
				scanf(" %d\n", &arr[i])
			} else {
				scanf(" %d", &arr[i])
			}
		}
		mtx[j] = arr
	}
	defer flush()

	printf("%v\n", minimumArea(mtx))
}
