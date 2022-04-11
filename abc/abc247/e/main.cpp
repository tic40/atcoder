#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,x,y;
  cin >> n >> x >> y;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int tx,ty,b;
  tx = ty = b = -1;
  ll ans = 0;
  REP(r,n) {
    if (a[r] == x) tx = r;
    if (a[r] == y) ty = r;
    if (a[r] < y || x < a[r]) tx = ty = b = r;
    int l = min(tx,ty);
    ans += l - b;
  }

  cout << ans << endl;
  return 0;
}
