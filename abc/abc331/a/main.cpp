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
  int M,D; cin >> M >> D;
  int y,m,d; cin >> y >> m >> d;

  d++;
  if (d > D) {
    d = 1;
    m++;
    if (m > M) {
      m = 1;
      y++;
    }
  }
  printf("%d %d %d\n",y,m,d);
  return 0;
}