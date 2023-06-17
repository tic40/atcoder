#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  int n3 = n*3;
  vector<int> a(n3);
  REP(i,n3) { cin >> a[i]; a[i]--; }
  vector g(n,vector<int>());
  REP(i,n3) g[a[i]].push_back(i);

  vector<pair<int,int>> ans(n);
  REP(i,n) ans[i] = { g[i][1], i };
  sort(ans.begin(),ans.end());
  for(auto [_,v]: ans) cout << v+1 << " ";
  return 0;
}