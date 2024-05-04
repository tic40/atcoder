#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];
  vector<P> pa;
  REP(i,n) pa.emplace_back(b[i]-a[i],i);

  sort(pa.begin(),pa.end());
  ll ans += b[pa.back().second];
  REP(i,n-1) ans += a[pa[i].second];
  cout << ans << endl;
  return 0;
}