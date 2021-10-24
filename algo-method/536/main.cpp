#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> to(n);
  vector<int> deg(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    to[a].push_back(b);
    deg[b]++;
  }

  priority_queue<int, vector<int>, greater<int>> q;
  REP(i,n) if (deg[i] == 0) q.push(i);

  vector<int> ans;
  while(q.size()) {
    int v = q.top(); q.pop();
    ans.push_back(v);

    for (int u: to[v]) {
      deg[u]--;
      if (deg[u] == 0) q.push(u);
    }
  }

  cout << ((int)ans.size() == n ? "Yes" : "No") << endl;
  return 0;
}