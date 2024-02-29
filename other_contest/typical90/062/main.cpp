#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector g(n,vector<int>());
  queue<int> q;
  vector<bool> used(n);
  REP(i,n) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(i);
    g[b].push_back(i);
    if (i == a || i == b) q.push(i);
  }

  vector<int> ans;
  while(q.size()) {
    int now = q.front(); q.pop();
    if (used[now]) continue;
    used[now] = true;
    ans.push_back(now);
    for(int v: g[now]) if (!used[v]) q.push(v);
  }

  if ((int)ans.size() == n) {
    reverse(ans.begin(),ans.end());
    for(int v: ans) cout << v+1 << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}