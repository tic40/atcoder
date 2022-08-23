#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m);
  REP(i,m) cin >> a[i];
  a.push_back(0);
  a.push_back(n+1);
  sort(a.begin(),a.end());

  vector<int> d;
  REP(i,m+1) {
    int diff = a[i+1] - a[i];
    if (diff > 1) d.push_back(diff-1);
  }
  int k = *min_element(d.begin(),d.end());

  int ans = 0;
  for(int v: d) ans += (v+k-1)/k;

  cout << ans << endl;
  return 0;
}