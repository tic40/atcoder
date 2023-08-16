#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n; cin >> n;
  vector<int> a(n-1);
  REP(i,n-1) cin >> a[i];

  vector<mint> dp(n);
  vector<mint> s(n+1); // dp の累積和
  for(int i = n-2; i >= 0; i--) {
    // サイコロの出目をすべて求めると O(N^2) となるため、累積和で高速化
    mint now = s[i+1] - s[i+1+a[i]];
    now *= mint(1) / (a[i]+1);
    now += 1;
    // 0 出ることを考慮する
    // 0　以外が出る確率を p としたとき、1/p が 0 以外が出る期待値となる
    now *= mint(a[i]+1)/a[i];
    dp[i] = now;
    s[i] = s[i+1] + dp[i];
  }

  cout << dp[0].val() << endl;
  return 0;
}