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
    g[x].push_back(y);
  }

  vector mem(8889, vector<int>());
  vector<int> vec, cnt(n);

  auto dfs = [&](auto self, int i, int sum) {
    if (i == n) {
      if (mem[sum].size()) {
        for(auto v: {mem[sum], vec}) {
          cout << v.size() << endl;
          for(auto k: v) cout << k+1 << " ";
          cout << endl;
        }
        exit(0);
      }
      mem[sum] = vec;
      return;
    }

    self(self,i+1,sum);
    if (cnt[i] == 0) {
      vec.push_back(i);
      for(auto v: g[i]) cnt[v]++;
      self(self,i+1,sum+a[i]);
      for(auto v: g[i]) cnt[v]--;
      vec.pop_back();
    }
  };

  dfs(dfs,0,0);
  return 0;
}