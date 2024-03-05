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
  vector<int> h(3),w(3);
  REP(i,3) cin >> h[i];
  REP(i,3) cin >> w[i];

  auto ok = [](int x) { return 1 <= x; };
  auto f = [&](int i, int j, int k, int l) {
    int w0 = w[0] - (i+j);
    int w1 = w[1] - (k+l);
    int h0 = h[0] - (i+k);
    int h1 = h[1] - (j+l);
    int h2 = h[2] - (w0+w1);
    int w2 = w[2] - (h0+h1);
    return h2 == w2 && ok(w0) && ok(w1) && ok(w2) && ok(h0) && ok(h1) && ok(h2);
  };

  int ans = 0;
  for(int i = 1; i <= 28; i++) {
    for(int j = 1; j <= 28; j++) {
      for(int k = 1; k <= 28; k++) {
        for(int l = 1; l <= 28; l++) {
          ans += f(i,j,k,l);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}