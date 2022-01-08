#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n,k;
vector<int> x;

void solve() {
  int ans = INF;
  REP(i,n-k+1) {
    int l = x[i];
    int r = x[i+k-1];
    int d;
    if (l <= 0 && r <= 0) {
      d = abs(l);
    } else if (0 < l && 0 < r) {
      d = r;
    } else {
      d = min(abs(l)*2+abs(r), abs(r)*2+abs(l));
    }
    ans = min(ans, d);
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> k;
  x.resize(n);
  REP(i,n) cin >> x[i];

  solve();
  return 0;
}