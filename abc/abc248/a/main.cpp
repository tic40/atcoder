#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  string s; cin >> s;
  vector<int> v(10);
  REP(i,9) v[s[i]-'0']++;
  REP(i,10) if(v[i] == 0) cout << i << endl;
  return 0;
}