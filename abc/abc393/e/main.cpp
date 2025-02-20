#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  const int m = 1e6;
  // cnt[i] := A にある i で割り切れる数の個数
  vector<int> cnt(m+1);
  REP(i,n) cnt[a[i]]++;

  for(int i = 1; i <= m; i++) {
    for(int j = i+i; j <= m; j+=i) cnt[i] += cnt[j];
  }

  // ans[i] := A から i を含む k 個を選んだときの gcd の最大値
  vector<int> ans(m+1);
  for(int i = 1; i <= m; i++) if (cnt[i] >= k) {
    for(int j = i; j <= m; j+=i) ans[j] = i;
  }

  REP(i,n) cout << ans[a[i]] << endl;
  return 0;
}
