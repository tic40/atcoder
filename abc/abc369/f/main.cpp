#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

P op(P a, P b) { return max(a,b); }
P e() { return P(0,-1); }

int main() {
  int h,w,n; cin >> h >> w >> n;
  vector<P> coins;
  REP(i,n) {
    int r,c; cin >> r >> c;
    coins.emplace_back(r,c);
  }
  // x の昇順にする
  sort(coins.begin(),coins.end());

  const int MX = 200005;
  segtree<P,op,e> t(MX);
  vector<int> pre(n);
  REP(i,n) {
    int y = coins[i].second;
    auto [lis,idx] = t.prod(0,y+1);
    pre[i] = idx;
    t.set(y, P(lis+1,i));
  }

  string ans;
  int r = h, c = w;
  auto mv = [&](P p) {
    auto [nr,nc] = p;
    while (r > nr) { r--; ans += 'D'; }
    while (c > nc) { c--; ans += 'R'; }
  };

  auto [lis,i] = t.all_prod();
  while (i != -1) {
    mv(coins[i]);
    i = pre[i];
  }
  mv(P(1,1));
  reverse(ans.begin(), ans.end());
  cout << lis << endl;
  cout << ans << endl;
  return 0;
}