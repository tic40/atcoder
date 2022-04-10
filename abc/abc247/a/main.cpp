#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  string s; cin >> s;
  rotate(s.rbegin(), s.rbegin()+1, s.rend());
  s[0]='0';
  cout << s << endl;
  return 0;
}
