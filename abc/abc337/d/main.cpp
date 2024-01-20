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
  vector<string> s(h+2);
  REP(i,h) {
    cin >> s[i+1];
    s[i+1] = 'x' + s[i+1] + 'x';
  }
  h+=2;
  w+=2;
  s[0] = string(w,'x');
  s[h-1] = string(w,'x');

  vector<string> rs(w);
  REP(i,w) rs[i] = string(h,'.');
  REP(i,w) {
    REP(j,h) {
      rs[i][j] = s[h-1-j][i] ;
    }
  }

  int ans = 1e9;
  auto f = [&](int h, int w, vector<string> s) -> void {
    vector g(h,vector<int>());
    REP(i,h) REP(j,w) {
      if (s[i][j] == 'x') g[i].push_back(j);
    }
    // o の数の累積和
    vector su(h,vector<int>(w+1));
    REP(i,h) REP(j,w) {
      su[i][j+1] = su[i][j] + (s[i][j] == 'o' ? 1 : 0);
    }

    REP(i,h) {
      int sz = g[i].size();
      REP(j,sz-1) {
        int l = g[i][j];
        int r = g[i][j+1];
        if (r-l-1 < k) continue;
        int now = k;
        for(int ii = l+1; ii+k <= r; ii++) {
          now = min(now, k - (su[i][ii+k] - su[i][ii]));
        }
        ans = min(ans,now);
      }
    }
  };

  f(h,w,s);
  f(w,h,rs);

  cout << (ans == 1e9 ? -1 : ans) << endl;
  return 0;
}