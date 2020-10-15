#!/usr/bin/env python3

s = str(input())

def sq(a):
    ret = [0 for _ in range(len(a)*2-1)]
    for i in range(len(a)):
        for j in range(len(a)):
            ret[i+j] += int(a[i])*int(a[j])
            ret[i+j] %= 10
    return "".join(map(str,ret))

def dfs(prefix):
    g = sq(prefix)
    if g == s:
        return prefix
    if len(g) >= len(s):
        return None
    if g[:len(prefix)] != s[:len(prefix)]:
        return None
    for i in range(10):
        x = dfs(prefix+str(i))
        if x:
            return x
    return None

print(dfs("") or "-1")
