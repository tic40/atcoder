#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,sum=0,r=0; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  ll ans=0;
  REP(l,n) {
    while(r < n) {
      if ((sum^a[r]) != (sum+a[r])) break;
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