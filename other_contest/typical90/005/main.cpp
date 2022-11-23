#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const int MOD = 1e9+7;
const int LOG = 62; // Nの対数

int main() {
  ll n; int b,k;
  cin >> n >> b >> k;
  vector<int> c(k);
  REP(i,k) cin >> c[i];

  // dp[i] と dp[j] を掛け合わせて dp[i+j] を得る処理
  // tj: 10^j を b で割ったあまり
  auto mul = [&](const vector<ll>& dpi, const vector<ll>& dpj, ll tj) {
    vector<ll> res(b);
    REP(p,b) REP(q,b) {
      int now = (p * tj + q) % b;
      res[now] += dpi[p] * dpj[q];
      res[now] %= MOD;
    }
    return res;
  };

  vector<ll> ten(LOG, 10); // ten[i]: 10^(2^i) を b で割ったあまり
  for (int i = 1; i < LOG; ++i) ten[i] = (ten[i-1] * ten[i-1])%b;

  // dp[2^i][r] を doubl[i][r] で書くことにする
  vector doubl(LOG, vector<ll>(b));
  // 初期化 (doubl[0] := dp[1])
  REP(i,k) doubl[0][c[i] % b] += 1;

  // ダブリング
  for (int i = 1; i < LOG; ++i) doubl[i] = mul(doubl[i-1],doubl[i-1],ten[i-1]);

  // ダブリングした結果をもとに答えを求める
  vector<ll> ans(b);
  ans[0] = 1;
  // n を二の冪乗の積で表すときに、2^i を含むかどうか
  REP(i,LOG) if (n & (1LL << i)) ans = mul(ans, doubl[i], ten[i]);

  cout << ans[0] << endl;
  return 0;
}