#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

map<int,vector<int>> mp;
set<int> visited;

void dfs(int i) {
  if (visited.count(i)) return;
  visited.insert(i);
  for(auto v: mp[i]) dfs(v);
}
int main() {
  int n; cin >> n;
  REP(i,n) {
    int a,b; cin >> a >> b;
    mp[a].push_back(b);
    mp[b].push_back(a);
  }

  dfs(1);
  cout << *visited.rbegin() << endl;
  return 0;
}