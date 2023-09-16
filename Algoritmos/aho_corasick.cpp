int trie[MAX][26], nds = 1;
int fin[MAX], fail[MAX], sure_fail[MAX];

int add(string &s){
  int cr = 0, x;

  for(const auto &c: s){
    x = c - 'a';

    if(trie[cr][x] == 0) trie[cr][x] = nds++;
    cr = trie[cr][x];
  }

  fin[cr] = 1;
  return cr;
}

void build(){
  int x, cr = 0;

  deque<int> q;
  q.PB(cr);

  while(!q.empty()){
    cr = q.F(); q.P_F();

    FOR(i, 0, 26){
      x = trie[cr][i];
      if(x) q.PB(x);

      if(cr == 0) continue;
      if(x == 0){
        trie[cr][i] = trie[fail[cr]][i];
        continue;
      }

      fail[x] = trie[fail[cr]][i];
      sure_fail[x] = fin[fail[x]] ? fail[x] : sure_fail[fail[x]];
    }
  }
}