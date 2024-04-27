#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  vector<int> c(9);
  REP(i,9) cin >> c[i];

  auto solve1 = [&]() {
    vector<int> p(9);
    REP(i,9) p[i] = i;
    int cnt = 0, tot = 0;
    do {
      bool ok = true;
      auto f = [&](int i, int j, int k) {
        vector<P> d;
        d.emplace_back(p[i],c[i]);
        d.emplace_back(p[j],c[j]);
        d.emplace_back(p[k],c[k]);
        sort(d.begin(),d.end());
        return d[0].second != d[1].second;
      };
      ok &= f(0,1,2);
      ok &= f(3,4,5);
      ok &= f(6,7,8);
      ok &= f(0,3,6);
      ok &= f(1,4,7);
      ok &= f(2,5,8);
      ok &= f(0,4,8);
      ok &= f(2,4,6);
      if (ok) cnt++;
      tot++;
    } while(next_permutation(p.begin(),p.end()));
    return (double)cnt/tot;
  };

  auto solve2 = [&]() {
    int cnt = 0;

    vector<bool> visited(9);
    int now = 0;
    auto dfs = [&](auto self) {
      if (now == 9) { cnt++; return; }
      auto f = [&](int i, int j, int k) {
        vector<int> d;
        if (visited[i]) d.push_back(c[i]);
        if (visited[j]) d.push_back(c[j]);
        if (visited[k]) d.push_back(c[k]);
        return (d.size() != 2 || d[0] != d[1]);
      };

      bool ok = true;
      ok &= f(0,1,2);
      ok &= f(3,4,5);
      ok &= f(6,7,8);
      ok &= f(0,3,6);
      ok &= f(1,4,7);
      ok &= f(2,5,8);
      ok &= f(0,4,8);
      ok &= f(2,4,6);
      if (!ok) return;

      REP(ni,9) {
        if (visited[ni]) continue;
        visited[ni] = true;
        now++;
        self(self);
        visited[ni] = false;
        now--;
      }
    };

    dfs(dfs);
    double ans = (double)cnt / 362880.0;
    return ans;
  };

  // 解説放送解
  // double ans = solve1();
  double ans = solve2();
  printf("%.10f\n",ans);
  return 0;
}