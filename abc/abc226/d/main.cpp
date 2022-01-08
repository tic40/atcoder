#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }

int n;
vector<pair<ll,ll>> p;

void solve() {
  set<pair<ll,ll>> st;
  REP(i,n) REP(j,n) {
    if (i == j) continue;
    auto [x1, y1] = p[i];
    auto [x2, y2] = p[j];
    ll xd = x2-x1;
    ll yd = y2-y1;
    ll g = gcd(abs(xd),abs(yd));
    st.insert( { xd/g, yd/g } );
  }
  cout << st.size() << endl;
  return;
}

int main() {
  cin >> n;
  p.resize(n);
  REP(i,n) {
    ll x,y; cin >> x >> y;
    p[i] = { x, y };
  }

  solve();
  return 0;
}