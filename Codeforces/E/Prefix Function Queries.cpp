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
 
using namespace std;

vector<int> z;

int nds = 0;
int trie[1000005][26];
int pref[1000005];

void kmp(string &s){
	int j = 0;

	FOR(i, 1, s.size()){
		j = z[i - 1];

		while(j > 0 and s[i] != s[j]) j = z[j - 1];
		if(s[i] == s[j]) j++;
		z[i] = j;
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, x; cin >> s;

	z.assign(s.size() + 10, 0);

	kmp(s);

	memset(trie, -1, sizeof(trie));
	memset(pref, -1, sizeof(pref));

	int q, n = s.size(), j, c, cr; cin >> q;
	FOR(ab, 0, q){
		cin >> x;
		cr = 0;

		FOR(i, 0, x.size()){
			c = x[i] - 'a';

			if(trie[cr][c] != -1){
				cr = trie[cr][c];
				z[i + n] = pref[cr];
				continue;
			}else trie[cr][c] = ++nds;

			cr = trie[cr][c];

			j = z[i + n - 1];

			while(j > 0 and x[i] != (j >= n ? x[j - n] : s[j])) j = z[j - 1];
			if(x[i] == (j >= n ? x[j - n] : s[j])) j++;
			z[i + n] = j;
			pref[cr] = j;
		}

		FOR(i, n, n + x.size()) cout << z[i] << " ";

		cout << "\n";
	}
 
	return 0;
}