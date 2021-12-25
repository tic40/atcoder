#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int l,r; cin >> l >> r;
  string s; cin >> s;

  string fs = s.substr(0,l-1);
  string ms = s.substr(l-1,r-l+1);
  string rs = s.substr(r);

  reverse(ms.begin(),ms.end());
  string ans = fs + ms + rs;

  cout << ans << endl;
  return 0;
}