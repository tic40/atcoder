#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
using Edge = pair<int,P>;

int main() {
  int n,q; cin >> n >> q;
  priority_queue<Edge,vector<Edge>,greater<Edge>> pq;

  vector<int> x,y;
  auto add = [&](int nx, int ny) {
    int v = x.size();
    REP(i,v) {
      int dist = abs(nx-x[i]) + abs(ny-y[i]);
      pq.emplace(dist,P(i,v));
    }
    x.push_back(nx);
    y.push_back(ny);
  };

  REP(i,n) {
    int nx,ny; cin >> nx >> ny;
    add(nx,ny);
  }

  dsu uf(n+q);
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int nx,ny; cin >> nx >> ny;
      add(nx,ny);
    }
    if (t == 2) {
      while(pq.size()) {
        auto [a,b] = pq.top().second;
        if (!uf.same(a,b)) break;
        pq.pop();
      }

      if (pq.size() == 0) { cout << -1 << endl; continue; }

      int k = pq.top().first;
      cout << k << endl;
      while(pq.size() && pq.top().first == k) {
        auto [a,b] = pq.top().second;
        pq.pop();
        uf.merge(a,b);
      }
    }
    if (t == 3) {
      int u,v; cin >> u >> v; u--; v--;
      cout << (uf.same(u,v) ? "Yes" : "No") << endl;
    }
  }
  return 0;
}