#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int N, M;
vector<vector<int>> G(100000);
vector<int> dp(100000, -1);

int rec(int v) {
  if (dp[v] != -1) return dp[v];

  int res = 0;
  for (auto nv : G[v]) res = max(res, rec(nv) + 1);
  return dp[v] = res;
}

int main() {
  cin >> N >> M;

  int x, y;
  REP(i,M) {
    cin >> x >> y;
    G[x-1].push_back(y-1);
  }

  int res = 0;
  REP(i,N) res = max(res, rec(i));
  cout << res << endl;
}