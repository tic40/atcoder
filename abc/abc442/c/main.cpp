#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  REP(i,m) {
    int a,b; cin >> a >> b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  REP(i,n) {
    int s = g[i].size();
    ll r = n - s - 1;
    cout << (r*(r-1)*(r-2)) / 6 << " ";
  }
  return 0;
}
