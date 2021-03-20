#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int h,w;
int used[16][16];

ll dfs(int i, int j, int a, int b) {
  if (a < 0 || b < 0) return 0;
  if (j == w) {
    j=0;
    i++;
  }
  if (i == h) return 1;

  if (used[i][j]) return dfs(i,j+1,a,b);
  ll res = 0;
  // 1x1を置く
  used[i][j] = true;
  res += dfs(i,j+1,a,b-1);

  // 1x2 を置く
  if (j+1 < w && !used[i][j+1]) {
    used[i][j+1] = true;
    res += dfs(i, j+1, a-1, b);
    used[i][j+1] = false;
  }
  // 2x1 を置く
  if (i+1 < h && !used[i+1][j+1]) {
    used[i+1][j] = true;
    res += dfs(i, j+1, a-1, b);
    used[i+1][j] = false;
  }
  used[i][j] = false;
  return res;
}

int main() {
  cin >> h >> w;
  int a,b;
  cin >> a >> b;
  ll ans = dfs(0,0,a,b);
  cout << ans << endl;

  return 0;
}