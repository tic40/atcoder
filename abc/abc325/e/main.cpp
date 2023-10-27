#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,int>;
const ll LINF = 1e18; //numeric_limits<ll>::max();
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n; ll a,b,c;
  cin >> n >> a >> b >> c;
  vector d(n,vector<ll>(n));
  REP(i,n) REP (j,n) cin >> d[i][j];

  // 解説放送解
  auto solve1 = [&]() -> void {
    auto dijk = [&](int sv, ll b, ll c) {
      vector<ll> dist(n,LINF);
      dist[sv] = 0;
      vector<bool> done(n);
      REP(ni,n) {
        P best(LINF,0);
        REP(i,n) if (!done[i]) chmin(best, P(dist[i],i));
        int v = best.second;
        done[v] = true;
        REP(i,n) chmin(dist[i], dist[v]+d[v][i]*b+c);
      }
      return dist;
    };
    auto d1 = dijk(0,a,0);
    auto d2 = dijk(n-1,b,c);
    ll ans = LINF;
    REP(i,n) chmin(ans,d1[i]+d2[i]);
    cout << ans << endl;
  };

  solve1();
  return 0;
}