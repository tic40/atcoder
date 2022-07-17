#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> p(n);
  REP(i,n) {
    cin >> p[i];
    p[i]--;
  }

  // なんターン目に食べられたか
  vector<int> ans(n,-1);

  if (k == 1) {
    REP(i,n) ans[p[i]] = i;
    for(int v: ans) cout << v+1 << endl;
    return 0;
  }

  set<int> st;
  vector<vector<int>> g(n);

  REP(i,n) {
    int now = p[i];
    auto it = st.upper_bound(now);

    // debug
    // cout << i << ": ";
    // for(int v: st) cout << v << " ";
    // cout << endl;

    if(it == st.end()) {
      st.insert(now);
      g[now].push_back(now);
      continue;
    }

    // cout << "add " << *it << " " << now << " " << i << endl;
    g[*it].push_back(now);
    if ((int)g[*it].size() == k) {
      for(auto v: g[*it]) {
        ans[v] = i;
      }
      st.erase(*it);
    } else {
      st.erase(*it);
      st.insert(now);
    }
  }

  for(int v: ans) cout << (v == -1 ? -1 : v+1) << endl;
  return 0;
}