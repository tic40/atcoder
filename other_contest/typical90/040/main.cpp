#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

int main() {
  int n,w; cin >> n >> w;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  mf_graph<int> g(n+2);
  REP(i,n) {
    int k; cin >> k;
    REP(j,k) {
      int c; cin >> c;
      c--;
      g.add_edge(c,i,INF);
    }
  }
  REP(i,n) {
    g.add_edge(n,i,a[i]);
    g.add_edge(i,n+1,w);
  }
  ll ans = accumulate(a.begin(),a.end(),0LL);
  ans -= g.flow(n,n+1);
  cout << ans << endl;
  return 0;
}