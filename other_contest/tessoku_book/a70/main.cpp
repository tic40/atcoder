#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n,m; cin >> n >> m;
  int start = 0;
  REP(i,n) {
    int a; cin >> a;
    if (a == 1) start += 1<<i;
  }
  vector<int> b(m);
  REP(i,m) {
    int x,y,z; cin >> x >> y >> z;
    x--; y--; z--;
    b[i] = (1<<x)+(1<<y)+(1<<z);
  }

  vector g(1<<n,vector<int>());
  REP(bit,1<<n) REP(i,m) g[bit].push_back(bit ^ b[i]);

  queue<int> q;
  q.push(start);
  vector<int> dist(1<<n, INF);
  dist[start] = 0;

  while(q.size()) {
    int bit = q.front(); q.pop();
    int ndist = dist[bit]+1;
    for(int nbit: g[bit]) {
      if (dist[nbit] <= ndist) continue;
      q.push(nbit);
      dist[nbit] = ndist;
    }
  }

  cout << (dist[goal] == INF ? -1 : dist[(1<<n)-1]) << endl;
  return 0;
}