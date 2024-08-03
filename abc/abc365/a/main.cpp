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
  int y; cin >> y;
  if (y % 4 != 0) cout << 365 << endl;
  else if (y % 4 == 0 && y % 100 != 0) cout << 366 << endl;
  else if (y % 100 == 0 && y % 400 != 0) cout << 365 << endl;
  else if (y % 400 == 0) cout << 366 << endl;
  else cout << 365 << endl;
  return 0;
}