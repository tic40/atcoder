#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

vector<pair<int, int>> prime_factorize(int n) {
  vector<pair<int,int>> res;
  for (int a = 2; a * a <= n; a++) {
    if (n % a != 0) continue;
    int ex = 0;
    while (n % a == 0) { ++ex; n /= a; }
    res.push_back({a, ex});
  }
  if (n != 1) res.push_back({n, 1});
  return res;
}

int main() {
  int n; cin >> n;
  map<int, int> mp;
  for(int i = 2; i <= n; i++) {
    auto pf = prime_factorize(i);
    for(auto v: pf) mp[v.first] += v.second;
  }

  vector<int> nums;
  for(auto v: mp) nums.push_back(v.second);

  // dp[i][j]: i個目までの素因数で約数の個数がj個
  vector dp(n,vector<int>(77));
  dp[0][1] = 1;
  REP(i,(int)nums.size()) REP(j,76) REP(cnt,nums[i]+1) {
    dp[i+1][min(76, j*(cnt+1))] += dp[i][j];
  }

  cout << dp[nums.size()][75] << endl;
  return 0;
}