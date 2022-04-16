#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  string s; cin >> s;
  vector<int> m(10);
  for(char c: s) m[c-'0']++;
  REP(i,10) if(m[i] == 0) cout << i << endl;
  return 0;
}