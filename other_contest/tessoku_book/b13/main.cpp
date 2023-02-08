#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  ll ans = 0, sum = 0;
  int r = 0;
  REP(l,n) {
    while(r < n && sum+a[r] <= k) {
      sum += a[r];
      r++;
    }
    ans += r-l;
    if (r == l) r++;
    else sum -= a[l];
  }
  cout << ans << endl;
  return 0;
}