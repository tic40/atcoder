#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

struct Event {
  int l,r,x;
  Event(int l = 0, int r = 0, int x = 0): l(l),r(r),x(x) {}
};

int op(int x, int y) { return max(x,y); }
int e() { return 0; }
int mapping(int f, int x) { return x += f; }
int composition(int f, int g) { return f+g; }
int id() { return 0; }

int main() {
  int n,d,w; cin >> n >> d >> w;
  const int MX = 4e5+5; // 座標の最大値
  vector events(MX,vector<Event>());
  REP(i,n) {
    int t,x; cin >> t >> x;
    events[t].emplace_back(x,x+w,1);
    events[t+d].emplace_back(x,x+w,-1);
  }

  int ans = 0;
  lazy_segtree<int,op,e,int,mapping,composition,id> seg(MX);
  REP(t,MX) {
    for(auto ev: events[t]) seg.apply(ev.l, ev.r, ev.x);
    ans = max(ans,seg.all_prod());
  }
  cout << ans << endl;

  return 0;
}