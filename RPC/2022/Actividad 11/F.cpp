#include <bits/stdc++.h>

using namespace std;

void morse(map<char,string> &f){
  f.insert(make_pair('A', ".-"));
  f.insert(make_pair('B', "-..."));
  f.insert(make_pair('C', "-.-."));
  f.insert(make_pair('D', "-.."));
  f.insert(make_pair('E', "."));
  f.insert(make_pair('F', "..-."));
  f.insert(make_pair('G', "--."));
  f.insert(make_pair('H', "...."));
  f.insert(make_pair('I', ".."));
  f.insert(make_pair('J', ".---"));
  f.insert(make_pair('K', "-.-"));
  f.insert(make_pair('L', ".-.."));
  f.insert(make_pair('M', "--"));
  f.insert(make_pair('N', "-."));
  f.insert(make_pair('O', "---"));
  f.insert(make_pair('P', ".--."));
  f.insert(make_pair('Q', "--.-"));
  f.insert(make_pair('R', ".-."));
  f.insert(make_pair('S', "..."));
  f.insert(make_pair('T', "-"));
  f.insert(make_pair('U', "..-"));
  f.insert(make_pair('V', "...-"));
  f.insert(make_pair('W', ".--"));
  f.insert(make_pair('X', "-..-"));
  f.insert(make_pair('Y', "-.--"));
  f.insert(make_pair('Z', "--.."));

  f.insert(make_pair('0', "-----"));
  f.insert(make_pair('1', ".----"));
  f.insert(make_pair('2', "..---"));
  f.insert(make_pair('3', "...--"));
  f.insert(make_pair('4', "....-"));
  f.insert(make_pair('5', "....."));
  f.insert(make_pair('6', "-...."));
  f.insert(make_pair('7', "--..."));
  f.insert(make_pair('8', "---.."));
  f.insert(make_pair('9', "----."));

}

int main()
{
    string s, out = "";
    map<char,string> map;
    morse(map);
    
    getline(cin, s);
    for(auto &c : s){
        c = toupper(c);
        if(map.count(c)){
            out += map[c];
        }
    }

    if(out.size() == 0){
        cout << "NO\n";
        return 0;
    }

    bool puede = true;
    int n = out.size();
    for(int i=0, j=n-1; i<=n/2; i++, j--){
        if(out[i] != out[j]){
            puede = false;
        }
    }

    cout << (puede ? "YES" : "NO") << "\n";



    return 0;
}