#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const int MOD = 1e9+7;
using mint = modint1000000007;

const int MAX = 1e5+1;
ll fac[MAX], finv[MAX], inv[MAX];

// combinationテーブルを作る
void com_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
  return;
}

// 二項係数nCr
ll com(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  com_init();
  mint sum_max = 0, sum_min = 0;

  sort(a.begin(),a.end());
  for(int i = k-1; i <= n; i++) sum_max += com(i,k-1) * a[i];
  reverse(a.begin(),a.end());
  for(int i = k-1; i <= n; i++) sum_min += com(i,k-1) * a[i];

  mint ans = sum_max - sum_min;
  cout << ans.val() << endl;

  return 0;
}