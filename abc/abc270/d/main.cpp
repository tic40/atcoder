#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int n,k;
vector<int> a(100);
// memo[i][j] := 残りの石の数i, 手番j のときの最適値
vector memo(10005, vector<int> (2, INF));

int f(int x, int t) {
  if (memo[x][t] != -INF && memo[x][t] != INF) return memo[x][t];

  REP(i,k) {
    if (x-a[i] < 0) break;
    if (t == 1) {
      memo[x][t] = max(memo[x][t], a[i] + f(x-a[i], 0));
    } else {
      memo[x][t] = min(memo[x][t], f(x-a[i], 1));
    }
  }

  if (memo[x][t] == INF || memo[x][t] == -INF) return 0;
  return memo[x][t];
}

int main() {
  cin >> n >> k;
  REP(i,k) cin >> a[i];
  REP(i,10001) memo[i][1] = -INF;

  cout << f(n,1) << endl;
  return 0;
}