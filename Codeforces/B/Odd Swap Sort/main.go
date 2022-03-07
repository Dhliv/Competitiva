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

func main() {
	defer Flush()

	var t, n, ib, pb, x int;
	var able bool;
	Scanf("%d\n", &t);

	for ab := 0; ab < t; ab++{
		Scanf("%d\n", &n);
		ib, pb = -1, -1;
		able = true;

		for i := 0; i < n - 1; i++{
			Scanf("%d ", &x);
			if((x & 1) == 1){
				if(ib > x){
					able = false;
				}
				ib = x;
			}else{
				if(pb > x){
					able = false;
				}
				pb = x;
			}
		}

		Scanf("%d\n", &x);
		if((x & 1) == 1){
			if(ib > x){
				able = false;
			}
			ib = x;
		}else{
			if(pb > x){
				able = false;
			}
			pb = x;
		}

		if(able){
			Printf("yes\n");
		} else{
			Printf("no\n");
		}
	}
}
