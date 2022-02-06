package main

import (
	"bufio"
	"fmt"
	"os"
)

var rdr *bufio.Reader = bufio.NewReader(os.Stdin)
var wr *bufio.Writer = bufio.NewWriter(os.Stdout)

func Printf(f string, a ...interface{}) {
	fmt.Fprintf(wr, f, a...)
}

func Scanf(f string, a ...interface{}) {
	fmt.Fscanf(rdr, f, a...)
}

func Flush() {
	wr.Flush()
}

type point struct {
	x, y int
}

func isOnLine(a, b, p *point) bool {
	return ((p.y-a.y)*(b.x-a.x) - (b.y-a.y)*(p.x-a.x)) == 0
}

func main() {
	defer Flush()

	var n, x0, y0, x, y int
	Scanf("%d %d %d\n", &n, &x0, &y0)
	ori := point{x: x0, y: y0}

	puntos := make([]point, n)
	seen := make([]bool, n)

	for i := 0; i < n; i++ {
		Scanf("%d %d\n", &x, &y)
		puntos[i] = point{x: x, y: y}
	}

	var shots int = 0
	for i := 0; i < n; i++ {
		if !seen[i] {
			shots++
			for j := i + 1; j < n; j++ {
				if seen[j] {
					continue
				}
				seen[j] = isOnLine(&puntos[i], &puntos[j], &ori)
			}
		}
	}

	Printf("%v\n", shots)
}
