#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
using D = map<ll,set<ll>>;

int main() {
  map<char,P> moves;
  moves['U'] = { 0, 1 };
  moves['R'] = { 1, 0 };
  moves['D'] = { 0, -1 };
  moves['L'] = { -1, 0 };

  int n,m; cin >> n >> m;
  ll sx,sy; cin >> sx >> sy; sx--; sy--;

  D xs,ys;
  REP(i,n) {
    ll x,y; cin >> x >> y; x--; y--;
    xs[y].insert(x);
    ys[x].insert(y);
  }

  int ans = 0;
  auto f = [&](D& xs, D& ys, ll y, ll l, ll r) -> void {
    if (l > r) swap(l,r);
    auto& st = xs[y];
    auto it = st.lower_bound(l);
    while(it != st.end() && *it <= r) {
      ys[*it].erase(y);
      it = st.erase(it);
      ans++;
    }
  };

  REP(i,m) {
    char d; ll c; cin >> d >> c;
    auto [dx, dy] = moves[d];
    ll nx = sx + dx * c;
    ll ny = sy + dy * c;
    sy == ny ? f(xs,ys,sy,sx,nx) : f(ys,xs,sx,sy,ny);

    sx = nx; sy = ny;
  }

  cout << sx+1 << " " << sy+1 << " " << ans << endl;
  return 0;
}