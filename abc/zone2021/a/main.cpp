#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  string s; cin >> s;
  int ans = 0;
  REP(i,s.size()-3) {
    if ("ZONe" == s.substr(i,4)) ans++;
  }
  cout << ans << endl;
  return 0;
}