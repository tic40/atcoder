#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int k; cin >> k;
  k--;

  vector<ll> ans;
  auto dfs = [&](auto self, ll i) -> void {
    ans.push_back(i);
    REP(ni,i%10) self(self,i*10+ni);
  };

  for(ll i = 1; i <= 9; i++) dfs(dfs,i);
  sort(ans.begin(),ans.end());
  cout << ans[k] << endl;
  return 0;
}