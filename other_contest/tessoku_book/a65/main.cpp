#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

vector g(1e5,vector<int>());
vector<int> ans(1e5);

int dfs(int i, int p) {
  int now = 0;
  for(int v: g[i]) if (v != p) now += dfs(v,i);
  ans[i] = now;
  return now+1;
}

int main() {
  int n; cin >> n;
  for(int i = 1; i < n; i++) {
    int a; cin >> a;
    a--;
    g[a].push_back(i);
  }

  dfs(0,-1);
  REP(i,n) cout << ans[i] << " ";
  return 0;
}