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

func main() {
	var s string
	var n, ans, x, y int
	var p []int

	scanf("%s\n%d\n", &s, &n)

	p = append(p, 0)
	for i := 1; i < len(s); i++ {
		ans = p[i-1]
		if s[i] == s[i-1] {
			ans++
		}

		p = append(p, ans)
	}

	for i := 0; i < n; i++ {
		scanf("%d %d\n", &x, &y)
		x--
		y--
		printf("%d\n", p[y]-p[x])
	}

	wr.Flush()
}
