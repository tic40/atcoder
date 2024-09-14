#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
using mint = modint998244353;

int main() {
  int n; ll k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];;
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+a[i];

  // dp[i] := 最後の分割位置が i の場合の数
  vector<mint> dp(n+1);
  dp[0] = 1;
  mint tot = 1;
  unordered_map<ll,mint> dpsum;
  dpsum[0]=1;
  for(int i = 1; i <= n; i++) {
    // REP(j,i) dp[i] += dp[j];
    dp[i] += tot;

    // REP(j,i) if (s[j] == s[i]-k) dp[i] -= dp[j];
    dp[i] -= dpsum[s[i]-k];
    tot += dp[i];
    dpsum[s[i]] += dp[i];
  }
  cout << dp[n].val() << endl;
  return 0;
}