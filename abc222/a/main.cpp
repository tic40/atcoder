#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  string s; cin >> s;
  int n = 4-s.size();
  REP(i,n) s='0'+s;
  cout << s << endl;
  return 0;
}