#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector g(n, vector<int>());
  REP(_,q) {
    int x,y; cin >> x >> y;
    x--; y--;
    g[x].push_back(y); // x < y のため一方向で良い
  }

  vector mem(8889, vector<int>());
  vector<int> vec, cnt(n);

  auto output_ans = [](vector<int> v1, vector<int> v2) {
    for(auto vec: {v1,v2}) {
      cout << vec.size() << endl;
      for(auto v: vec) cout << v << " ";
      cout << endl;
    }
  };

  auto dfs = [&](auto self, int i, int now) {
    if (i == n) {
      if (mem[now].size()) {
        output_ans(mem[now], vec);
        exit(0);
      }
      mem[now] = vec;
      return;
    }

    self(self, i+1, now);
    if (cnt[i] == 0) {
      vec.push_back(i+1);
      for(int v: g[i]) cnt[v]++;
      self(self, i+1, now+a[i]);
      vec.pop_back();
      for(int v: g[i]) cnt[v]--;
    }
  };

  dfs(dfs,0,0);
  return 0;
}