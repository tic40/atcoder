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
  vector<int> p(m), y(m);
  vector<vector<int>> g(n);

  REP(i,m) {
    cin >> p[i] >> y[i];
    p[i]--;
    g[p[i]].push_back(y[i]);
  }

  REP(i,n) sort(g[i].begin(), g[i].end());

  REP(i,m) {
    auto arr = g[p[i]];
    auto it = lower_bound(arr.begin(), arr.end(), y[i]);
    printf("%06d%06d\n", p[i]+1, it-arr.begin()+1);
  }
  return 0;
}