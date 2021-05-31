vector<int> z;

void kmp(string &s){
  int j, n = s.size();
  z.resize(n);
  
  FOR(i, 1, n){
    j = z[i - 1];
    while(j > 0 and s[i] != s[j]) j = z[j - 1];
    if(s[i] == s[j]) j++;
    z[i] = j;
  }
}