#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int MOD = 1e9+7;

int n;
ll k;
vector<int> a;

void solve() {
  ll right_sum = 0, tot_sum = 0;
  REP(i,n) {

    for (int j = i+1; j < n; j++) {
      if (a[j] < a[i]) right_sum++;
    }

    REP(j,n) {
      if (a[i] < a[j]) tot_sum++;
    }

  }

  ll ans = k * right_sum % MOD;
  // 等差数列の和
  // ans += (0 + tot_sum * (k-1)) * k / 2;
  ans += k * (k-1) / 2 % MOD * tot_sum;

  ans %= MOD;

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}