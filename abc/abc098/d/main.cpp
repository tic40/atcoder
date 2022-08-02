#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  ll sum = 0, ans = 0;
  int r = 0;

  REP(l,n) {
    while(r < n) {
      if ( (sum+a[r]) != (sum^a[r])) break;
      sum += a[r];
      r++;
    }

    ans += r-l;
    if (r == l) r++;
    sum -= a[l];
  }

  cout << ans << endl;
  return 0;
}