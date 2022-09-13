#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

vector<vector<int>> g(26);
vector<bool> visited(26);

bool dfs(int i, int target) {
  if (i == target) return true;
  if (visited[i]) return false;
  visited[i] = true;

  for(int v: g[i]) if (dfs(v,target)) return true;

  return false;
}

int main() {
  int n; cin >> n;
  REP(i,n) {
    char a,b; cin >> a >> b;
    g[a-'a'].push_back(b-'a');
    g[b-'a'].push_back(a-'a');
  }
  string s,t; cin >> s >> t;

  bool ok = true;
  REP(i,(int)s.size()) {
    if (s[i] == t[i]) continue;
    REP(j,26) visited[j] = false;
    visited = vector<bool>(26);
    if (!dfs(s[i]-'a', t[i]-'a')) ok = false;
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}