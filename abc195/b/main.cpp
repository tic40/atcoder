#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int a,b,w; cin >> a >> b >> w;
  w*=1000;
  int mi = INF, mx = 0;

  for(int i = 1; i <= 1e6; i++) {
    if (a*i <= w && w <= b*i) {
      mi = min(mi, i);
      mx = max(mx, i);
    }
  }
  if (mi == INF) cout << "UNSATISFIABLE";
  else cout << mi << " " << mx;

  return 0;
}