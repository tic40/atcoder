#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<tuple<int,int,int>> pa(n);
  REP(i,n) {
    int a,c; cin >> a >> c;
    pa[i] = {a,-c,i};
  }
  sort(pa.rbegin(),pa.rend());

  int nc = 1e9+5;
  vector<int> ans;
  REP(i,n) {
    auto [_,c,id] = pa[i];
    c = -c;
    if (c < nc) ans.push_back(id+1);
    nc = min(c,nc);
  }

  sort(ans.begin(),ans.end());
  cout << ans.size() << endl;
  for(auto v: ans) cout << v << " ";
  return 0;
}