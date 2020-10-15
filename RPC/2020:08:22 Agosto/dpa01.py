t=int(input())

k=[]
i=1
while i <= t:
	n=int(input())
	k.append(n)
	i+=1

for x in k:
	j=1
	ceros=[]
	while j < x:
		modulo=x%j
		if modulo == 0:
			ceros.append(j)
		j+=1
	suma=sum(ceros)
	if suma < x:
		print("deficient")
	elif suma == x:
		print("perfect")
	else:
		print("abundant")