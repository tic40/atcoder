#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

int main() {
  ll sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;

  ll dx = tx - sx;
  ll dy = ty - sy;

  // 縦の移動は必ず +1
  ll ans = abs(dy);
  if (dx < 0) {
    dx = abs(dx);
    if ((sx+sy) % 2 == 1) sx--;
    if ((tx+ty) % 2 == 0) tx++;
    sx -= abs(dy);
    if (tx < sx) ans += (sx-tx+1)/2;
  } else {
    dx = abs(dx);
    dx = abs(dx);
    if ((sx+sy) % 2 == 0) sx++;
    if ((tx+ty) % 2 == 1) tx--;
    sx += abs(dy);
    if (tx > sx) ans += (tx-sx+1)/2;
  }

  cout << ans << endl;
  return 0;
}