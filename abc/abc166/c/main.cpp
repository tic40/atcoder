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
  int n, m; cin >> n >> m;
  int h[n]; REP(i,n) { cin >> h[i]; }

  Graph g(n);
  REP(i,m) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  ll ans = 0;
  REP(i,n) {
    int ok = true;
    for(auto x : g[i]) {
      if (h[i] <= h[x]) { ok = false; break; }
    }
    if (ok) ans++;
  }
  COUT(ans);

  return 0;
}
