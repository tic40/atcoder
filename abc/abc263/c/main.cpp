#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int n,m;
vector<vector<int>> ans;

void dfs(vector<int> cur) {
  if ((int)cur.size() == n) {
    ans.push_back(cur);
    return;
  }

  int l = ((int)cur.size() == 0) ? 1 : cur.back() + 1;
  for(int i = l; i <= m; i++) {
    vector nv = cur;
    nv.push_back(i);
    dfs(nv);
  }
  return;
}

int main() {
  cin >> n >> m;
  dfs({});
  for(auto v: ans) {
    for(int t: v) cout << t << " ";
    cout << endl;
  }
  return 0;
}