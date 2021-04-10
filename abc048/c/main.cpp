#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  int n,x; cin >> n >> x;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  ll ans = 0;
  REP(i,n-1) {
    if (x < a[i]+a[i+1]) {
      int diff = a[i] + a[i+1] - x;
      ans += diff;
      a[i+1] = max(0, a[i+1]-diff);
    }
  }

  cout << ans << endl;
  return 0;
}