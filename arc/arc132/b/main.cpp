#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n; cin >> n;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  // 昇順かどうか
  bool up = true;
  if (p[0] == 1 && p[1] == n) up = false;
  if (p[0] == p[1]+1) up = false;

  int ans = INF;
  if (up) {
    REP(i,n) {
      if (p[i] == 1) {
        ans = min(ans, i);
        ans = min(ans, n-i+2); // 反転、末尾、反転
        break;
      }
    }
  } else {
    REP(i,n) {
      if (p[i] == n) {
        ans = min(ans, i+1);
        ans = min(ans, n-i+1);
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}