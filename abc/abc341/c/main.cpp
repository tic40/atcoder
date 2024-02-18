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

// URDL
const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};

int main() {
  int h,w,n; cin >> h >> w >> n;
  string t; cin >> t;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  int ans = 0;
  REP(i,h) REP(j,w) {
    if (s[i][j] == '#') continue;
    int ni = i, nj = j;
    int ok = true;
    for(auto c: t) {
      int d = 0;
      if (c == 'U') d = 0;
      if (c == 'R') d = 1;
      if (c == 'D') d = 2;
      if (c == 'L') d = 3;
      ni += di[d];
      nj += dj[d];
      if (s[ni][nj] == '#') { ok = false; break; }
    }
    if (ok) ans++;
  }
  cout << ans << endl;
  return 0;
}