package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
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

func sortMatrix(grid [][]int) [][]int {
	for y := len(grid) - 1; y > 0; y-- {
		d := []int{}
		dy := y
		for x := 0; x < len(grid)-y; x++ {
			d = append(d, grid[x][dy])
			dy++
		}

		slices.Sort(d)
		dy = y
		for x := 0; x < len(grid)-y; x++ {
			grid[x][dy] = d[x]
			dy++
		}
	}

	for x := range len(grid) {
		d := []int{}
		dx := x
		for y := 0; y < len(grid)-x; y++ {
			d = append(d, grid[dx][y])
			dx++
		}

		slices.Sort(d)
		slices.Reverse(d)

		dx = x
		for y := 0; y < len(grid)-x; y++ {
			grid[dx][y] = d[y]
			dx++
		}
	}

	return grid
}

func main() {
	var n int
	scanf("%d\n", &n)
	var mtx [][]int = make([][]int, n)

	for j := range n {
		arr := make([]int, n)
		for i := range n {
			if i == 0 {
				scanf("%d", &arr[i])
			} else if i == n-1 {
				scanf(" %d\n", &arr[i])
			} else {
				scanf(" %d", &arr[i])
			}
		}
		mtx[j] = arr
	}
	defer flush()

	printf("%v\n", sortMatrix(mtx))
}
