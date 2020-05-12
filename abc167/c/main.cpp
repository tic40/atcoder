#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x)  cout << #x << " = " << (x) << endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,m,x;
  cin >> n >> m >> x;
  int c[n],a[n][m];
  REP(i,n) {
    cin >> c[i];
    REP(j,m) cin >> a[i][j];
  }

  ll ans = INF;

  for (int bit = 1; bit < (1<<n); bit++) {
    vector<int> s;
    for (int i = 0; i <= n; i++) {
      if (bit & (1 << i-1)) s.push_back(i-1);
    }

    ll tot = 0;
    vector<int> totx(m,0);

    for(auto v: s) {
      tot += c[v];
      REP(i,m) {
        totx[i] += a[v][i];
      }
    }
    int ok = true;
    REP(i,m) {
      if (totx[i] < x) ok = false;
    }
    if (ok) ans = min(ans, tot);
  }

  if (ans == INF) COUT(-1);
  else COUT(ans);

  return 0;
}
