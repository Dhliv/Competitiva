import random

n = 500000
m = 987
q = 500000

print(n, m, q)
x = [[] for __ in range(m)]
for i in range(m):
    x[i].append(random.randint(0,255))
for i in range(500000-m):
    x[random.randint(0,random.randint(0,random.randint(0,m-1)))].append(random.randint(0,255))
for i in range(m):
    print(len(x[i])," ".join(map(str,x[i])))
types = [1,3,2]
for i in range(q):
    ty = types[random.randint(0, len(types)-1)]#random.randint(1,3)
    if ty == 1:
        idx = random.randint(0,random.randint(0,random.randint(0,m-1)))
        p = random.randint(1,n-len(x[idx])+1)
        print(ty,idx+1,p)
    elif ty == 2:
        print(ty,random.randint(1,n))
    else:
        idx = random.randint(0,random.randint(0,random.randint(0,m-1)))
        l = random.randint(1,len(x[idx]))
        r = random.randint(1,len(x[idx]))
        if l>r:
            l,r = r,l
        print(ty,idx+1,l,r)
