#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int MOD = 998244353;

// 2のx乗のMODを計算しておく
const int max_n = 2000005;
vector<ll> b(max_n);

int main() {
  ll n,d; cin >> n >> d;

  b[0] = 1;
  REP(i,max_n) b[i+1] = b[i] * 2 % MOD;

  ll ans = 0;
  REP(i,n) {
    // 自身を頂点に取る場合
    // i+dがn未満であれば、i+dの頂点から自由に選べる.
    // 2^d * 頂点数(2^(i)) = 2^(d+i)
    if (i+d < n) {
      ans += b[i+d];
      ans %= MOD;
    }

    // 左右を要点に取る場合
    ll l = max(1LL, i+d-n+1); // 最も浅いとり方
    ll h = min(d-1, n-i-1); // 最も深いとり方
    if (l <= h) {
      // 左側の頂点数 2^(i-1)
      // 右側の頂点数 2^(d-i-1)
      // 2^(i-1) * 2^(d-i-1) = 2^(d-2)
      // 2^(d-2) * 頂点数 2^i = 2^(d+i-2)
      // 2^(d+i-2) * 範囲(h-l+1)
      ans += b[d+i-2]*(h-l+1);
      ans %= MOD;
    }
  }

  ans *= 2; // 2頂点のパスは逆方向にも取れるので x2 する
  ans %= MOD;

  cout << ans << endl;
  return 0;
}