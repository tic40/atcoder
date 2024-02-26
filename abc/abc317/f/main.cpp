#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353;
using T = tuple<int,bool,bool>;
using VT = vector<T>;

int main() {
  const int m = 3;
  ll n; cin >> n;
  vector<int> a(m);
  REP(i,m) cin >> a[i];

  n++;
  vector<int> ds; // ds[i] := 各桁の bit
  while(n) { ds.push_back(n&1); n >>= 1; }
  reverse(ds.begin(),ds.end());

  // 桁DP
  // dp[i][VT] := i 桁目までみたときに状態が VT のときの組み合わせの数
  // VT := [md,lt,z]
  //   md: 割った余り
  //   lt: N未満になることが確定したかどうかflag
  //   z: 0 or 1
  map<VT,mint> dp;
  dp[VT(3)] = 1;
  for(int digit: ds) {
    map<VT,mint> pre;
    swap(dp,pre);
    for(auto [s,num]: pre) {
      REP(b,1<<m) {
        // b の bit に 1 が奇数個あるときは xor で 0 にならないのでスキップ
        if(__builtin_parity(b)) continue;
        VT ns;
        bool ok = true;
        REP(i,m) {
          auto [md, lt, z] = s[i];
          int nb = b>>i & 1; // 今の桁
          md = (md*2+nb)%a[i];
          z |= nb;
          // less than が確定していない かつ 今の桁の値が digit より大きい
          if (!lt && nb > digit) ok = false;
          lt |= nb < digit;
          ns.emplace_back(md,lt,z);
        }
        if (ok) dp[ns] += num;
      }
    }
  }

  mint ans = dp[VT(3,{0,1,1})];
  cout << ans.val() << endl;
  return 0;
}