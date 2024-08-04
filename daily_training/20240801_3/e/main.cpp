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
  vector<int> g(n);
  REP(i,n) {
    int a; cin >> a; a--;
    g[i] = a;
  }

  int v = 0;
  REP(i,n) v = g[v];

  vector<int> visited(n);
  vector<int> ans;
  REP(i,n) {
    if (visited[v] == 1) break;
    ans.push_back(v);
    visited[v] = 1;
    v = g[v];
  }
  cout << ans.size() << endl;
  for(auto v: ans) cout << v+1 << " ";
  return 0;
}