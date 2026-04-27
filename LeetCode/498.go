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

type p struct {
	x, y int
}

func findDiagonalOrder(mat [][]int) []int {
	var deltas = []p{
		{x: -1, y: 1},
		{x: 1, y: -1},
	}

	dir := 0
	x, y := 0, 0
	sol := []int{mat[x][y]}

	n, m := len(mat), len(mat[0])
	for x != n-1 || y != m-1 {
		nx, ny := x+deltas[dir].x, y+deltas[dir].y

		if dir == 0 {
			if nx < 0 && ny < m {
				nx = 0
				dir = 1 - dir
			} else if nx < 0 && ny == m {
				nx, ny = 1, m-1
				dir = 1 - dir
			} else if ny == m {
				nx, ny = nx+2, m-1
				dir = 1 - dir
			}
		} else {
			if ny < 0 && nx < n {
				ny = 0
				dir = 1 - dir
			} else if ny < 0 && nx == n {
				nx, ny = n-1, 1
				dir = 1 - dir
			} else if nx == n {
				nx, ny = n-1, ny+2
				dir = 1 - dir
			}
		}

		sol = append(sol, mat[nx][ny])
		x, y = nx, ny
	}

	return sol
}

func main() {
	var n, m int
	scanf("%d %d\n", &n, &m)
	var arr [][]int = make([][]int, n)

	for i := range n {
		arr[i] = make([]int, m)
		for j := range m {
			if j > 0 && j+1 != m {
				scanf(" %d", &arr[i][j])
				continue
			} else if j+1 == m {
				scanf(" %d\n", &arr[i][j])
				continue
			}

			scanf("%d", &arr[i][j])
		}
	}
	defer flush()

	printf("%v\n", findDiagonalOrder(arr))
}
