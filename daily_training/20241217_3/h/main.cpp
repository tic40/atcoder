#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = 1e15;

int main() {
  int n; cin >> n;
  vector g(n,vector<P>());
  ll tot = 0;
  REP(i,n-1) {
    int a,b,c; cin >> a >> b >> c; a--; b--;
    g[a].emplace_back(b,c);
    g[b].emplace_back(a,c);
    tot += c;
  }

  auto bfs = [&](int i) {
    vector<ll> dist(n,LINF);
    priority_queue<P> pq;
    pq.emplace(0,i);
    dist[i] = 0;

    while(pq.size()) {
      auto [cost,cur] = pq.top(); pq.pop();
      if (dist[cur] < cost) continue;

      for(auto [ni,ncost]: g[cur]) {
        if (dist[ni] <= cost+ncost) continue;
        pq.emplace(cost+ncost,ni);
        dist[ni] = cost+ncost;
      }
    }
    return dist;
  };

  auto dist1 = bfs(0);
  auto farthest1 = max_element(dist1.begin(),dist1.end()) - dist1.begin();
  auto dist2 = bfs(farthest1);
  auto farthest2 = max_element(dist2.begin(),dist2.end()) - dist2.begin();
  ll ans = tot*2 - dist2[farthest2];
  cout << ans << endl;
  return 0;
}