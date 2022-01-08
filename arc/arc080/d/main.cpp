#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,h,w; cin >> h >> w >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int ans[h][w];
  int cur = 0;
  REP(i,h) REP(j,w) {
    int nj = i%2 ? w-j-1 : j;
    if (a[cur] == 0) cur++;
    ans[i][nj] = cur+1;
    a[cur]--;
  }

  REP(i,h) REP(j,w) {
    cout << ans[i][j];
    if (j == w-1) cout << endl;
    else cout << " ";
  }

  return 0;
}