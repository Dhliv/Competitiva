#include <climits>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std ;
int bc(int v) {
   int r = 0 ;
   while (v) {
      r++ ;
      v &= v-1 ;
   }
   return r ;
}
int calcparity(const string &s) {
   int seen = 0 ;
   int p = 0 ;
   for (auto c : s) {
      c -= 'a' ;
      p += bc(((1<<c)-1) & seen) ;
      seen |= 1<<c ;
   }
   return p&1 ;
}
int diff(const string &a, const string &b) {
   int r = 0 ;
   for (int i=0; i<(int)a.size(); i++)
      r += (a[i] != b[i]) ;
   return r ;
}
struct e {
   int v, flow, c, rev ;
} ;
struct g {
   int v ;
   vector<vector<e>> adj ;
   vector<int> level ;
   g(int v_) : v(v_), adj(v_), level(v_) {}
   void addedge(int a, int b, int c) {
      e ab {b,0,c,(int)adj[b].size()} ;
      e ba {a,0,0,(int)adj[a].size()} ;
      adj[a].push_back(ab) ;
      adj[b].push_back(ba) ;
   }
   int bfs(int s, int t);
   int sendflow(int s, int flow, int t, vector<int> &ptr) ;
   int dinic(int s, int t) ;
} ;
int g::bfs(int s, int t) {
   for (auto &v : level)
      v = -1 ;
   level[s] = 0 ;
   vector<int> q ;
   q.push_back(s) ;
   for (int qg=0; qg<(int)q.size(); qg++) {
      int a = q[qg] ;
      for (auto &e:adj[a])
         if (level[e.v] < 0 && e.flow < e.c) {
            level[e.v] = level[a]+1 ;
            q.push_back(e.v) ;
         }
   } 
   return level[t] >= 0 ;
}
int g::sendflow(int a, int flow, int t, vector<int> &start) {
   if (a == t) 
      return flow ;
   for (; start[a]<(int)adj[a].size(); start[a]++) {
      e &e = adj[a][start[a]] ;
      if (level[e.v] == level[a]+1 && e.flow < e.c) {
         int curf = min(flow, e.c-e.flow) ;
         int tempf = sendflow(e.v, curf, t, start) ;
         if (tempf > 0) {
            e.flow += tempf ;
            adj[e.v][e.rev].flow -= tempf ;
            return tempf ;
         }
      }
   }
   return 0 ;
}
int g::dinic(int s, int t) {
   if (s == t)
      return -1 ;
   int tot = 0 ;
   vector<int> start(v+1) ;
   while (bfs(s, t)) {
      for (auto &v : start)
         v = 0 ;
      while (int f=sendflow(s, INT_MAX, t, start))
         tot += f ;
   }
   return tot ;
}
int main() {
   int n ;
   cin >> n ;
   vector<string> w(n) ;
   for (auto &v : w)
      cin >> v ;
   vector<int> parity(n) ;
   for (int i=0; i<(int)w.size(); i++)
      parity[i] = calcparity(w[i]) ;
   g graph(n+2) ;
   for (int i=0; i<(int)parity.size(); i++) {
      if (parity[i])
         graph.addedge(i+2, 1, 1) ;
      else {
         graph.addedge(0, i+2, 1) ;
         for (int j=0; j<(int)parity.size(); j++)
            if (parity[j] && diff(w[i], w[j]) == 2)
               graph.addedge(i+2, j+2, 1) ;
      }
   }
   int f = graph.dinic(0, 1) ;
   int r = n - f ;
   cout << r << endl ;
}
