#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const int INF = 1e9+5;
const ll LINF = 1e18+5;
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

int main() {
  int n; cin >> n;
  vector<bool> a(2005);
  REP(i,n) {
    int x; cin >> x;
    a[x] = true;
  }

  REP(i,2005) {
    if (a[i]) continue;
    cout << i << endl;
    break;
  }
  return 0;
}
