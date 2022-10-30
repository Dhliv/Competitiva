import math
p = float(input())

def E(N):
	P = (1 - p)**N
	ans = P + N*(1 - P)
	return ans

mini = 100000000000000
ansPrint = 1
for i in range(2, 17):
	ans = E(i)
	if(ans < i):
		if(mini > ans/i):
			mini = ans/i
			ansPrint = i

print(ansPrint)