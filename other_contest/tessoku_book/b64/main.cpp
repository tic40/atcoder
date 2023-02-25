#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<P>());
  REP(i,m) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(b,c);
    g[b].emplace_back(a,c);
  }

  priority_queue<P, vector<P>, greater<P>> q;
  vector<int> dist(n,INF);
  auto push = [&](int i, int d) {
    if (dist[i] <= d) return;
    dist[i] = d;
    q.emplace(d,i);
  };

  push(0,0);
  while(q.size()) {
    auto [d,i] = q.top(); q.pop();
    if (dist[i] < d) continue;
    for(auto [ni,nc]: g[i]) push(ni,d+nc);
  }

  vector<int> ans;
  int i = n-1;
  int now = dist[n-1];
  while(1) {
    ans.push_back(i);
    if (i == 0) break;
    for(auto [ni,nc]: g[i]) {
      if (dist[ni] != now - nc) continue;
      i = ni;
      now -= nc;
    }
  }

  reverse(ans.begin(),ans.end());
  for(int v: ans) cout << v+1 << " ";
  return 0;
}