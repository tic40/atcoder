#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9+5;

int n,m,q;
vector<vector<int>> g;

void solve1() {
  REP(i,q) {
    int x,k; cin >> x >> k;
    x--;

    unordered_set<int> st = {x};
    vector<int> v = {x};
    int ans = x+1;
    REP(j,k) {
      vector<int> pv;
      swap(v,pv);
      for(int x: pv) for(int y: g[x]) {
        if (st.count(y)) continue;
        st.insert(y);
        v.push_back(y);
        ans += y+1;
      }
    }
    cout << ans << endl;
  }

}

void solve2() {
  vector<int> dist(n,INF);
  REP(i,q) {
    int x,k; cin >> x >> k;
    x--;

    queue<int> que;
    que.push(x);
    dist[x] = 0;
    vector<int> vs;
    while(que.size()) {
      int cur = que.front(); que.pop();
      vs.push_back(cur);
      if (k <= dist[cur]) continue;

      for(int v: g[cur]) {
        if (dist[cur]+1 < dist[v]) {
          dist[v] = dist[cur]+1;
          que.push(v);
        }
      }
    }

    int ans = 0;
    for(int v: vs) {
      ans += v+1;
      dist[v] = INF;
    }
    cout << ans << endl;
  }

}

int main() {
  cin >> n >> m;
  g.resize(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  cin >> q;
  // solve1();
  solve2();

  return 0;
}