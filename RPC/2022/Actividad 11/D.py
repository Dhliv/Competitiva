import math
s = input()

res = 0
ans = 0
mult = (1 << (len(s) - 1))
for i in range(len(s)):
	pow = len(s) - i - 1;
	aux = int(s[i])*mult/(1 << pow);
	aux *= 3**pow
	ans += aux

print(int(ans//mult), end="")

if(ans%mult != 0):
	ans -= mult*math.floor(ans/mult)
	while(ans%2 == 0):
		ans /= 2
		mult /= 2

	print(f" {int(ans)}/{int(mult)}")
else:
	print()