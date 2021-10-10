package main

import "fmt"

func main() {
	var n, a, ops, b int
	var first bool = true
	fmt.Scan(&n)

	fmt.Scan(&b)
	if b == 1 {
		ops++
		first = false
	}

	for ab := 1; ab < n; ab++ {
		fmt.Scan(&a)

		if a == 1 && b == 1 {
			ops++
		} else if a == 1 {
			if first {
				ops++
				first = false
			} else {
				ops += 2
			}
		}

		b = a
	}

	fmt.Println(ops)
}
