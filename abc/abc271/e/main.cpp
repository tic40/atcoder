#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const ll LINF = 1e18;

struct Edge {
  int a,b,c;
  Edge(int a, int b, int c) : a(a),b(b),c(c) {}
};

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector<Edge> es;
  REP(i,m) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    es.emplace_back(a,b,c);
  }
  // dp
  vector<ll> dist(n,LINF);
  dist[0] = 0;
  REP(i,k) {
    int ei; cin >> ei;
    ei--;
    auto [a,b,c] = es[ei];
    dist[b] = min(dist[b], dist[a]+c);
  }

  ll ans = dist[n-1];
  cout << (ans == LINF ? -1 : ans) << endl;
  return 0;
}