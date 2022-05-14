#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<vector<int>> g(n);
  vector<bool> usable(n);
  queue<int> q;
  REP(i,n) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(i);
    g[b].push_back(i);
    if (a == i || b == i) {
      usable[i] = true;
      q.push(i);
    }
  }

  vector<int> v;
  while(q.size()) {
    int pos = q.front(); q.pop();
    v.push_back(pos);
    for (int i: g[pos]) {
      if (!usable[i]) {
        usable[i] = true;
        q.push(i);
      }
    }
  }

  if ((int)v.size() != n) {
    cout << -1 << endl;
    return 0;
  }

  reverse(v.begin(), v.end());
  for(int x: v) cout << x+1 << endl;

  return 0;
}