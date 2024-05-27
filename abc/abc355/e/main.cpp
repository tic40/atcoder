#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();

int main() {
  int n,l,r;
  cin >> n >> l >> r;
  int n2 = 1<<n;
  r++; // 半開区間として扱いたいので +1

  vector<int> dist(n2+1,INF), pre(n2+1,-1);
  queue<int> q;
  q.push(l); dist[l] = 0;
  while(q.size()) {
    int v = q.front(); q.pop();
    auto push = [&](int to) -> void {
      if (to < 0 || to > n2) return;
      if (dist[to] != INF) return;
      dist[to] = dist[v]+1;
      pre[to] = v;
      q.push(to);
    };
    REP(i,n+1) {
      push(v-(1<<i));
      push(v+(1<<i));
      if (v>>i & 1) break;
    }
  }

  int ans = 0;
  auto query = [&](int s, int t) {
    int sign = 1;
    if (s > t) { swap(s,t); sign = -1; }
    {
      int i = 0, j = s, w = t-s;
      while(w % 2 == 0) { j >>= 1; w >>= 1; i++; }
      cout << "? " << i << " " << j << endl;
    }
    int x; cin >> x;
    ans = (ans + x * sign + 100) % 100;
  };
  while(r != l) {
    query(pre[r],r);
    r = pre[r];
  }
  cout << "! " << ans << endl;
  return 0;
}