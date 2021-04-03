#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) b[i] = a[i]-(i+1);

  sort(b.begin(),b.end());
  // 中央値が最小となる
  ll x = b[n/2];

  ll ans = 0;
  REP(i,n) ans += abs(x-b[i]);

  cout << ans << endl;
  return 0;
}