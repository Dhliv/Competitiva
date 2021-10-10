package main

import "fmt"

var ele [3]int
var g [5][5]int

func poss(i, left int, fr bool) bool {
	if left == 0 {

		for j := 0; j < 3; j++ {
			for k := j + 1; k < 3; k++ {
				if fr {
					if g[ele[j]][ele[k]] == 0 {
						return false
					}
				} else {
					if g[ele[j]][ele[k]] == 1 {
						return false
					}
				}
			}
		}
		return true
	}

	var able bool = false
	for j := i + 1; j < 5-left+1; j++ {
		ele[3-left] = j
		able = able || poss(j, left-1, fr)
	}

	return able
}

func main() {
	var n, x, y int
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&x, &y)
		x--
		y--
		g[x][y] = 1
		g[y][x] = 1
	}

	if poss(-1, 3, true) || poss(-1, 3, false) {
		fmt.Println("WIN")
	} else {
		fmt.Println("FAIL")
	}
}
