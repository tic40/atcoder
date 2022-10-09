#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  vector<int> e,o;
  REP(i,n) {
    if (a[i] % 2 == 0) e.push_back(a[i]);
    else o.push_back(a[i]);
  }

  int ans = -1;
  if(e.size() >= 2) ans = max(ans, e[e.size()-1] + e[e.size()-2]);
  if(o.size() >= 2) ans = max(ans, o[o.size()-1] + o[o.size()-2]);

  cout << ans << endl;
  return 0;
}