#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int k; cin >> k;

  vector<ll> cand;
  auto dfs = [&](auto self, ll x) -> void {
    cand.push_back(x);
    int r = x % 10;
    x *= 10;
    REP(i,r) self(self,x+i);
  };

  for(int i = 1; i <= 9; i++) dfs(dfs,i);
  sort(cand.begin(),cand.end());
  cout << cand[k-1] << endl;
  return 0;
}