#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  sort(a.begin(),a.end());
  ll ans = 0;
  for(int j = 1; j < n-1; j++) {
    auto it1 = lower_bound(a.begin(),a.begin()+j, a[j])-1;
    auto it2 = upper_bound(a.begin()+j,a.end(), a[j]);
    int lidx = it1 - a.begin();
    int ridx = it2 - a.begin();
    ans += (ll)(lidx+1) * (n-ridx);
  }
  cout << ans << endl;
}