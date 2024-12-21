#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,ll>;

int main() {
  map<char,P> moves;
  moves['U'] = { 0, 1 };
  moves['R'] = { 1, 0 };
  moves['D'] = { 0, -1 };
  moves['L'] = { -1, 0 };

  int n,m; cin >> n >> m;
  ll sx,sy; cin >> sx >> sy; sx--; sy--;
  map<ll,set<ll>> mpx,mpy;
  REP(i,n) {
    ll x,y; cin >> x >> y;
    x--; y--;
    mpx[y].insert(x);
    mpy[x].insert(y);
  }

  int cnt = 0;
  REP(i,m) {
    char d; ll c; cin >> d >> c;
    auto [dx, dy] = moves[d];
    ll lx = sx, rx = sx + dx * c;
    ll ly = sy, ry = sy + dy * c;
    if (lx > rx) swap(rx,lx);
    if (ly > ry) swap(ly,ry);

    if (dy == 0) {
      auto it = mpx[sy].lower_bound(lx);
      vector<int> rm;
      while(*it <= rx && it != mpx[sy].end()) {
        rm.push_back(*it);
        cnt++;
        it++;
      }
      for(auto v: rm) {
        mpx[sy].erase(v);
        mpy[v].erase(sy);
      }
    }

    if (dx == 0) {
      auto it = mpy[sx].lower_bound(ly);
      vector<int> rm;
      while(*it <= ry && it != mpy[sx].end()) {
        rm.push_back(*it);
        cnt++;
        it++;
      }
      for(auto v: rm) {
        mpy[sx].erase(v);
        mpx[v].erase(sx);
      }
    }
    sx = sx + dx * c;
    sy = sy + dy * c;
  }
  cout << sx+1 << " " << sy+1 << " " << cnt << endl;
  return 0;
}