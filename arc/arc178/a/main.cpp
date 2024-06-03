#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());

  vector<int> ans(n);
  iota(ans.begin(),ans.end(),1);
  // for(auto v: ans) cout << v << " ";
  // cout << endl;
  REP(i,m) {
    if (a[i] == 1 || a[i] == n) { cout << -1 << endl; return 0; }
    swap(ans[a[i]-1],ans[a[i]]);
  }
  for(auto v: ans) cout << v << " ";
  return 0;
}