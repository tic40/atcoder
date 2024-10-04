#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

// TODO: 理解する
int main() {
  int n,m; ll k; cin >> n >> m >> k;
  vector<ll> A(n);
  REP(i,n) cin >> A[i];

  if (n == m) { REP(i,n) cout << 0 << " "; return 0; }

  auto a = A;
  sort(a.begin(),a.end());
  // 累積和
  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+a[i];
  // 残りの投票数
  ll remain = k - accumulate(a.begin(),a.end(),0LL);
  map<int,ll> ans;
  REP(i,n) {
    // i に x 票いれたときに当選できるか？
    auto judge = [&](ll x) {
      // i の現在の票数
      ll y = a[i]+x;
      // r := i より上位の当選者の index
      int r = lower_bound(a.begin(),a.end(),y+1) - a.begin();
      // l := 上位 m 人で一番最小票数の index
      int l = n-m;
      // 落選確定
      if (r < l) return false;
      // need := 上位 m 人(iを除く)が i の現在の票数を上回るのに必要な票数
      ll need = (y+1)*(r-l) - (s[r]-s[l]);
      // i が上位 m 人に含まれる場合の処理
      // a[i] と a[l-1] の差分を加算
      if (l <= i && i < r) need += a[i] - a[l-1];
      // nedd が 残り票数より大きければ i は当選できる
      return need > remain-x;
    };

    // 二分探索
    ll ok = remain+1, ng = -1;
    while(ok-ng > 1) {
      ll mid = (ok+ng)/2;
      if (judge(mid)) ok = mid;
      else ng = mid;
    }
    if (ok == remain+1) ok = -1;
    ans[a[i]] = ok;
  }

  REP(i,n) cout << ans[A[i]] << " ";
  return 0;
}