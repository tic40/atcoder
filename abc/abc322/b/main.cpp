#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  string s,t; cin >> s >> t;

  auto t1 = t.substr(0,n);
  auto t2 = t.substr(m-n);
  int ans = 3;
  if (s == t1 && s == t2) ans = 0;
  if (s == t1 && s != t2) ans = 1;
  if (s == t2 && s != t1) ans = 2;
  cout << ans << endl;
  return 0;
}