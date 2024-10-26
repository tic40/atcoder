#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
template<class T> void chmin(T&a, T b) { a = min(a,b); }

int main() {
  int n,m; cin >> n >> m;
  vector<int> min_r(m+1,m);
  REP(i,n) {
    int l,r; cin >> l >> r; l--; r--;
    chmin(min_r[l],r);
  }
  for (int l = m-1; l >= 0; l--) chmin(min_r[l],min_r[l+1]);
  ll ans = 0;
  REP(l,m+1) ans += min_r[l] - l;
  cout << ans << endl;
  return 0;
}