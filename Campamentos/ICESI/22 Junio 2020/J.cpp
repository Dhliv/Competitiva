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
#define MP make_pair
#define For(i, a, b) for(int i = a; i < b; i++)
#define forit(i, s) for(__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define foritr(i, s) for(__typeof ((s).rend ()) i = (s).rbegin (); i != (s).rend (); ++i)
 
using namespace std;


int main() {
    int n;
    string al;
    cin >> n;
    getline(cin, al);
    For(i,0,n){
        
        vector<int> v;
        string dato;
        bool se = true;
        
        getline(cin,dato);
        
        For(j,0,dato.length()){
            char a = dato[j];
            
            if(v.size()){
                if(a == ']'){
                    if(v.back() != a-2){
                        se = false;
                        break;
                    }else v.P_B();
                }
                else
                {
                    if(a == ')'){
                        
                        if(v.back() != a-1){
                        se = false;
                        break;
                        }else v.P_B();
                        
                    }else v.PB(a);
                }
            }else{
                if(a == ')' or a == ']'){
                    se = false;
                    break;
                }else v.PB(a);
            }
        }
        if(v.size()) se = false;
        
        if(se) cout << "Yes"<< endl;
        else cout << "No" << endl;
        
    }
    return 0;
}