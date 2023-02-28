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
  int h,w,k; cin >> h >> w >> k;
  vector<string> c(10);
  REP(i,h) cin >> c[i];
  int tot = 0;
  REP(i,h) REP(j,w) if (c[i][j] == '#') tot++;

  int ans = 0;
  REP(bit,1<<h) {
    int now = tot;
    auto nc = c;
    int popcnt = __builtin_popcount(bit);
    if (popcnt > k) continue;
    REP(i,h) {
      if (bit >> i & 1) {
        REP(j,w) {
          if (nc[i][j] == '#') continue;
          now++;
          nc[i][j] = '#';
        }
      }
    }
    vector<int> lcnt(w);
    REP(i,w) REP(j,h) if (nc[j][i] == '.') lcnt[i]++;
    sort(lcnt.rbegin(),lcnt.rend());
    REP(i,k-popcnt) now += lcnt[i];

    ans = max(ans,now);
  }
  cout << ans << endl;
  return 0;
}