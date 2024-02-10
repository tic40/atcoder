#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; cin >> n;
  map<ll,ll> memo;
  auto dfs = [&](auto self, ll x) -> ll {
    if (x < 2) { return 0LL; }
    if (memo.count(x)) return memo[x];
    return memo[x] = x + self(self, x/2) + self(self, (x+1)/2);
  };
  cout << dfs(dfs, n) << endl;
  return 0;
}