#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int h,w,m; cin >> h >> w >> m;
  vector<tuple<int,int,int>> tp(m);
  REP(i,m) {
    int t,a,x; cin >> t >> a >> x;
    t--; a--;
    tp[i] = {t,a,x};
  }
  const int mx = 2e5;
  const ll tot = (ll)h*w;

  vector<ll> col(mx+1);
  vector used(2,vector<int>(mx+1));
  // 操作を後ろから見ていく
  reverse(tp.begin(),tp.end());
  for(auto [t,a,x]: tp) {
    if (used[t][a]) continue;
    used[t][a] = 1;

    if (t == 0) { col[x] += w; h--; }
    else { col[x] += h; w--; }
  }

  ll sum = accumulate(col.begin(),col.end(),0LL);
  col[0] += tot - sum; // 初期の色0分を足す
  vector<pair<int,ll>> ans;
  REP(i,mx+1) if (col[i] > 0) ans.emplace_back(i,col[i]);

  cout << ans.size() << endl;
  for(auto [k,v]: ans) cout << k << " " << v << endl;
  return 0;
}