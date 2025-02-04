#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  vector<ll> xs;
  // g[i][j] := グループ i に入っている a の index の集合
  vector<vector<int>> g;

  // a[0] から順にグループに入れる全探索を考える
  // グループ分けは以下の2つの操作で考える
  //   - すでにあるグループに入れる
  //   - 新しいグループに入れる
  auto dfs = [&](auto& dfs, int i) -> void {
    if (i == n) {
      ll x = 0;
      REP(j,(int)g.size()) {
        ll sum = 0;
        for(int ni: g[j]) sum += a[ni];
        x ^= sum;
      }
      xs.push_back(x);
      return;
    }

    // すでにあるグループに入れる操作
    REP(j,(int)g.size()) {
      g[j].push_back(i);
      dfs(dfs,i+1);
      g[j].pop_back();
    }
    // 新しいグループに入れる
    g.push_back(vector<int>(1,i));
    dfs(dfs,i+1);
    g.pop_back();
  };

  dfs(dfs,0);
  sort(xs.begin(),xs.end());
  xs.erase(unique(xs.begin(),xs.end()),xs.end());
  cout << xs.size() << endl;
  return 0;
}