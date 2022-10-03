#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define PB push_back 
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
#define MAX 100005
 
using namespace std;

int nds;
int trie[MAX][10];
bool fin[MAX];

void add(string &s, bool &consistent){
	int cr = 0;
	int x;

	for(char &c: s){
		x = c - '0';

		if(trie[cr][x] == -1) trie[cr][x] = ++nds;
		cr = trie[cr][x];

		if(fin[cr]) consistent = false;
	}

	fin[cr] = true;
	if(cr != nds) consistent = false;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	int n;
	string s;

	FOR(ab, 0, t){
		nds = 0;
		cin >> n;
		FOR(i, 0, n*10 + 2){
			FOR(j, 0, 10) trie[i][j] = -1;
			fin[i] = false;
		}

		bool consistent = true;
		FOR(i, 0, n){
			cin >> s;
			add(s, consistent);
		}

		cout << (consistent ? "YES" : "NO") << "\n";
	}
  
	return 0;
}