#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using mint = modint1000000007;
using ll = long long;

const int MOD = 1000000007;
const int MAX = 100005;

ll fac[MAX], finv[MAX], inv[MAX];
void comInit() { // テーブルを作る前処理
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

ll com(int n, int k) { // 二項係数計算
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  int n; cin >> n;
  comInit();

  for(int k = 1; k <= n; k++) {
    mint sum = 0;
    for(int i = 1; i <= n/k+1; i++) {
      // 1..nからk以上の差になるものをi個選ぶ場合

      int s1 = n-(k-1)*(i-1);
      int s2 = i;
      sum += com(s1,s2);
    }
    cout << sum.val() << endl;
  }

  return 0;
}