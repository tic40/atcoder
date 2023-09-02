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
  int n; cin >> n;

  vector s(101, vector<bool>(101));
  REP(_,n) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    for(int i = a; i < b; i++) {
      for(int j = c; j < d; j++) {
        s[i][j] = true;
      }
    }
  }

  int ans = 0;
  REP(i,101) REP(j,101) if (s[i][j]) ans++;
  cout << ans << endl;
  return 0;
}