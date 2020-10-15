#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define PB push_back
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define MP make_pair
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;

int main(){
  int cases, street, aven, fri, A, S;
  cin >> cases;
  
  FOR(a, 0, cases){
    cin >> street >> aven >> fri;
    vector<int> S(fri), A(fri);

    FOR(i, 0, fri)
      cin >> S[i] >> A[i];
    
    sort(S.begin(), S.end());
    sort(A.begin(), A.end());
    
    if(fri%2)
      cout << "(Street: " << S[(fri)/2] << ", Avenue: " << A[fri/2] << ")\n";
    else
      cout << "(Street: " << S[fri/2 - 1] << ", Avenue: " << A[fri/2 - 1] << ")\n";

  }

  return 0;
}