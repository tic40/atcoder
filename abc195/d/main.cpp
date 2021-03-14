#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n,m,q;
vector<int> w,v,x;

void solve(int l, int r) {
  int ans = 0;
  vector<int> x2;
  REP(i,m) if (l < i || r < i) x2.push_back(x[i]);
  sort(x2.begin(), x2.end());
  vector<int> used(n);

  for(auto b: x2) {
    pair<int, int> best = {-1, -1}; // value, idx
    REP(i,n) {
      if (used[i] || b < w[i]) continue; // 使用済み、重さ超過
      if (best.first < v[i]) best = { v[i], i };
    }

    if (best.first == -1) continue;
    used[best.second]=1;
    ans += best.first;
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> m >> q;
  w.resize(n); v.resize(n);
  REP(i,n) cin >> w[i] >> v[i];
  x.resize(m);
  REP(i,m) cin >> x[i];

  REP(i,q) {
    int l,r; cin >> l >> r;
    solve(l-1, r-1);
  }

  return 0;
}