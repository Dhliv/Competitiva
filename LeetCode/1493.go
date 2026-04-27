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

func longestSubarray(nums []int) int {
	l, r := make([]int, len(nums)), make([]int, len(nums))

	c := 0
	for i := range len(nums) {
		if nums[i] == 0 {
			c = 0
		} else {
			c++
		}

		l[i] = c
	}

	c = 0
	for i := len(nums) - 1; i >= 0; i-- {
		if nums[i] == 0 {
			c = 0
		} else {
			c++
		}

		r[i] = c
	}

	ans := 0
	for i := range len(nums) {
		iz, dr := i-1, i+1
		val := 0
		if iz >= 0 {
			val += l[iz]
		}

		if dr < len(nums) {
			val += r[dr]
		}

		ans = max(ans, val)
	}

	return ans
}

func main() {
	var n int
	scanf("%d\n", &n)
	var arr []int = make([]int, n)

	for i := range n {
		if i == 0 {
			scanf("%d", &arr[i])
		} else if i == n-1 {
			scanf(" %d\n", &arr[i])
		} else {
			scanf(" %d", &arr[i])
		}
	}
	defer flush()

	printf("%v\n", longestSubarray(arr))
}
