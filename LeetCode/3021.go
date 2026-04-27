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

func flowerGame(n int, m int) int64 {
	nb := int64(n)
	mb := int64(m)
	return ((nb+1)/2)*(mb/2) + (nb/2)*((mb+1)/2)
}

func main() {
	var n, m int
	scanf("%d %d\n", &n, &m)
	// var mtx [][]int = make([][]int, n)

	// for j := range n {
	// 	arr := make([]int, m)
	// 	for i := range m {
	// 		if i == 0 {
	// 			scanf("%d", &arr[i])
	// 		} else if i == m-1 {
	// 			scanf(" %d\n", &arr[i])
	// 		} else {
	// 			scanf(" %d", &arr[i])
	// 		}
	// 	}
	// 	mtx[j] = arr
	// }
	defer flush()

	printf("%v\n", flowerGame(n, m))
}
