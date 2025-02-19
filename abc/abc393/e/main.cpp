#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  const int m = 1e6;

  // num[i] := a の分布
  // cnt[i] := j で割り切れる a の数のカウント
  // ans[i] := i を含む k 個の要素を a から選んだときの最大のgcd
  vector<int> num(m+1),cnt(m+1),ans(m+1);
  REP(i,n) num[a[i]]++;
  for(int j = 1; j <= m; j++) {
    for(int i = j; i <= m; i+=j) cnt[j]+=num[i];
  }

  // c[gcd] >= k := gcd で割り切れる a の数が k 以上あるとき
  for(int gcd = 1; gcd <= m; gcd++) if (cnt[gcd] >= k) {
    for(int i = gcd; i <= m; i+=gcd) ans[i] = gcd;
  }

  REP(i,n) cout << ans[a[i]] << endl;
  return 0;
}
