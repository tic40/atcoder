#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
  int n; ll c;
  cin >> n >> c;
  vector<ll> x(n),v(n);
  REP(i,n) cin >> x[i] >> v[i];

  vector<ll> m1(n+1),m2(n+1); // m1は片道, m2は往復
  REP(i,n) {
    // 累積和を取る: m[i+1] = m1[i] + v[i] - (x[i] - x[i-1])
    m1[i+1] = m1[i] + v[i] - x[i];
    m2[i+1] = m2[i] + v[i] - x[i]*2;
    if (0 < i) {
      m1[i+1] += x[i-1];
      m2[i+1] += x[i-1]*2;
    }
  }

  ll ans = *max_element(m1.begin(), m1.end());
  vector<ll> dp1(n+1), dp2(n+1); // dp[i] := iまでの最大値. dp1は片道, dp2は往復
  REP(i,n) {
    dp1[i+1] = max(dp1[i], m1[i+1]);
    dp2[i+1] = max(dp2[i], m2[i+1]);
  }

  ll sum = 0;
  for (int i = n-1; 0 <= i; i--) {
    sum += v[i];
    // 時計回りに進んで、その後に反時計回り
    chmax(ans, sum - (c-x[i]) + dp2[i]);
    // 反時計回りに進んで、その後に時計回り
    chmax(ans, sum - (c-x[i])*2 + dp1[i]);
  }

  cout << ans << endl;
  return 0;
}