#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int w,h,n; cin >> w >> h >> n;
  vector<P> s(n);
  REP(i,n) {
    int p,q; cin >> p >> q;
    s[i] = {p,q};
  }
  int x; cin >> x; vector<int> a(x);
  REP(i,x) cin >> a[i];
  int y; cin >> y; vector<int> b(y);
  REP(i,y) cin >> b[i];

  auto f = [&](int i) -> P {
    auto [nx,ny] = s[i];
    int aid = upper_bound(a.begin(),a.end(),nx) - a.begin() - 1;
    int bid = upper_bound(b.begin(),b.end(),ny) - b.begin() - 1;
    return P(aid,bid);
  };

  map<P,int> mp; // どのピースにイチゴが何個乗っているか
  REP(i,n) mp[f(i)]++;
  vector<int> cnt;
  for(auto [_,v]: mp) cnt.push_back(v);

  ll tot = (ll)(x+1)*(y+1);
  int mn = ((ll)mp.size() < tot) ? 0 : *min_element(cnt.begin(),cnt.end());
  int mx = *max_element(cnt.begin(),cnt.end());

  printf("%d %d\n", mn, mx);
  return 0;
}