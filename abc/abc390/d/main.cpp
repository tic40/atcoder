#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

template<class T> void uniq(T& vec) {
  sort(vec.begin(),vec.end());
  vec.erase(unique(vec.begin(),vec.end()),vec.end());
}

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  // g[i] := グループ i に入っている石の合計数
  vector<ll> ans,g;
  // a[0] から順にグループに入れる全探索を考える
  // グループ分けは以下の2択で DFS すればよい
  //   - すでにあるグループに入れる
  //   - 新しいグループに入れる
  auto dfs = [&](auto& dfs, int i) -> void {
    if (i == n) {
      ll x = 0;
      for(auto v: g) x ^= v;
      ans.push_back(x);
      return;
    }

    // すでにあるグループに入れる操作
    REP(j,(int)g.size()) {
      g[j] += a[i];
      dfs(dfs,i+1);
      g[j] -= a[i];
    }
    // 新しいグループを作って入れる操作
    g.push_back(a[i]);
    dfs(dfs,i+1);
    g.pop_back();
  };

  dfs(dfs,0);
  uniq(ans);
  cout << ans.size() << endl;
  return 0;
}