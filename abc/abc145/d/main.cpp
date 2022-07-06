#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using mint = modint1000000007;

mint choose(ll n, ll a) {
  mint x = 1, y = 1;
  for (int i = 0; i < a; i++) {
    x *= n-i;
    y *= i+1;
  }
  return x / y;
}

int main() {
  int x,y; cin >> x >> y;
  mint ans = 0;

  REP(a,x+1) {
    int dx = x - a;
    int dy = y - 2*a;
    if (dx < 0 || dy < 0) break;

    if (dx == dy*2) {
      int b = dy;
      ans += choose(a+b,min(a,b));
    }
  }

  cout << ans.val() << endl;
  return 0;
}