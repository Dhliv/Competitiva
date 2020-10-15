from operator import itemgetter
class BITSum:
   def __init__(self):
      self.arr = []
      self.sz = 0
   def resize(self, sz):
      self.sz = sz
      while len(self.arr) < 4*sz+1:
         self.arr.append(0)
   def dorange(self, a, b, v):
      while a < b:
         lowb = a & - a
         if lowb == 0:
            lowb = b + b
            while lowb & (lowb - 1):
               lowb &= lowb - 1
         while a + lowb > b:
            lowb >>= 1
         self.arr[2*a+lowb] += v
         a += lowb
   def accum(self, a):
      r = 0
      b = 1
      while b < 2*self.sz:
         r += self.arr[2*a+b]
         a &= ~b
         b *= 2
      return r
class BITMax:
   def __init__(self):
      self.arr = []
      self.sz = 0
   def resize(self, sz):
      self.sz = sz
      while len(self.arr) < 4*sz+1:
         self.arr.append(-1)
   def dorange(self, a, b, v):
      while a < b:
         lowb = a & - a
         if lowb == 0:
            lowb = b + b
            while lowb & (lowb - 1):
               lowb &= lowb - 1
         while a + lowb > b:
            lowb >>= 1
         self.arr[2*a+lowb] = v
         a += lowb
   def accum(self, a):
      r = -1 
      b = 1
      while b < 2*self.sz:
         r = max(r, self.arr[2*a+b])
         a &= ~b
         b *= 2
      return r
(n,m,q) = map(int, input().split())
dat = []
bm = BITMax()
bm.resize(n)
bsv = []
for i in range(m):
   t = list(map(int, input().split()))
   t.pop(0)
   dat.append(t)
   bsv.append(BITSum())
   bsv[i].resize(len(t))
cmds = []
setvals = []
def ints1(s):
   return int(s)-1
for i in range(q):
   t = list(map(ints1, input().split()))
   if t[0] == 0:
      bm.dorange(t[2], t[2]+len(dat[t[1]]), i)
   if t[0] == 1:
      ci = bm.accum(t[1])
      if ci < 0:
         t.append(0)
      else:
         t[1] -= cmds[ci][2]
         setvals.append([ci, i])
   cmds.append(t)
setvals = sorted(setvals, key=itemgetter(0))
svat = 0
for i in range(len(cmds)):
   while svat < len(setvals) and setvals[svat][0] == i:
      ci = setvals[svat][1]
      svat += 1
      di = cmds[i][1]
      add = cmds[ci][1]
      cmds[ci].append((bsv[di].accum(add) + dat[di][add]) % 256)
   if cmds[i][0] == 2:
      bsv[cmds[i][1]].dorange(cmds[i][2], cmds[i][3]+1, 1)
for i in range(len(cmds)):
   if cmds[i][0] == 1:
      print(cmds[i][-1]
)
