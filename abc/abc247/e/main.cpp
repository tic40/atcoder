#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,x,y;
  cin >> n >> x >> y;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  ll ans = 0;
  int nx = -1, ny = -1, b = -1;
  REP(i,n) {
    if (a[i] == x) nx = i;
    if (a[i] == y) ny = i;
    if (a[i] < y || x < a[i]) b = nx = ny = i;
    ans += min(nx,ny) - b;
  }

  cout << ans << endl;
  return 0;
}