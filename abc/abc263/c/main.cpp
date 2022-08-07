#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int n,m;
vector<vector<int>> ans;

void dfs(vector<int> v) {
  int sz = v.size();
  if (n == sz) {
    ans.push_back(v);
    return;
  }

  int l = sz == 0 ? 1 : v.back()+1;
  for(int i = l; i <= m; i++) {
    v.push_back(i);
    dfs(v);
    v.pop_back();
  }
  return;
}
int main() {
  cin >> n >> m;

  dfs({});
  for(auto v: ans) {
    for(int a: v) cout << a << " ";
    cout << endl;
  }
  return 0;
}