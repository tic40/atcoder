#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  ll tot = accumulate(a.begin(),a.end(),0LL);
  REP(i,n) a.push_back(a[i]);

  int n2 = n*2;
  ll mx = 0;
  ll now = a[0];
  REP(i,n2-1) {
    if (a[i+1] == a[i] || a[i+1] == (a[i]+1)%m) {
      now += a[i+1];
    } else {
      mx = max(mx,now);
      now = a[i+1];
    }
  }
  mx = max(mx,now);
  ll ans = max(0LL,tot - mx);
  cout << ans << endl;
  return 0;
}