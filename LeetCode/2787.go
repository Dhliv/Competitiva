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

var sol [301][301]int
var vals [301]int

var mod = 1000000007

var N int

func dp(i, left int) int {
	if left == 0 {
		return 1
	}

	if i == N || vals[i] > left {
		return 0
	}

	ans := sol[i][left]
	if ans != -1 {
		return ans
	}

	ans = dp(i+1, left)
	ans = (ans%mod + dp(i+1, left-vals[i])%mod) % mod

	sol[i][left] = ans

	return ans
}

func numberOfWays(n int, x int) int {
	for i := 0; i < n; i++ {
		val := i + 1
		vals[i] = val
		for j := 1; j < x; j++ {
			vals[i] *= val
		}

		for j := 0; j <= n; j++ {
			sol[i][j] = -1
		}
	}

	N = n

	return dp(0, n)
}

func main() {
	var n, x int
	scanf("%d %d\n", &n, &x)
	defer flush()

	printf("%d\n", numberOfWays(n, x))
}
