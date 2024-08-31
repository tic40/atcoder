#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int > a(n);
  REP(i,n) cin >> a[i];

  ll ans = n;
  int l = 0;
  while (l < n - 1) {
    int r = l + 1;
    int d = a[r] - a[l];
    while(r < n-1) {
      if (a[r+1] - a[r] != d) break;
      r++;
    }
    // len := l から等差数列になっている最大の長さ
    int len = r - l + 1;
    // len から2つの位置を決めたときの組み合わせ数 lenC2
    if (len > 1) ans += (ll)len * (len - 1) / 2;
    l = r;
  }
  cout << ans << endl;
  return 0;
}
