#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    g[a].push_back(b);
  }

  REP(i,n) {
    sort(g[i].begin(),g[i].end());
    for(int v: g[i]) cout << v << " ";
    cout << endl;
  }

  return 0;
}