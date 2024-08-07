#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n; cin >> n;
  ll tot = 0;
  vector g(n,vector<P>());
  REP(i,n-1) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
    tot += c * 2;
  }

  auto bfs = [&](int i) {
    vector<ll> dist(n,LINF);

    queue<int> q;
    q.push(i);
    dist[i] = 0;
    while (q.size()) {
      auto v = q.front(); q.pop();
      for (auto [nv,cost] : g[v]) if (dist[nv] > dist[v] + cost) {
        dist[nv] = dist[v] + cost;
        q.push(nv);
      }
    }
    return dist;
  };

  auto dist1 = bfs(0);
  int farthest = max_element(dist1.begin(), dist1.end()) - dist1.begin();
  auto dist2 = bfs(farthest);
  ll diameter = *max_element(dist2.begin(), dist2.end());

  cout << tot - diameter << endl;
  return 0;
}