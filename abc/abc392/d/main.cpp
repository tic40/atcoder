#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> k(n);
  vector g(n,vector<int>());
  vector cnt(n,vector<int>(1e5));
  REP(i,n) {
    cin >> k[i];
    REP(j,k[i]) {
      int a; cin >> a; a--;
      cnt[i][a]++;
      if (cnt[i][a] == 1) g[i].push_back(a);
    }
  }

  double ans = 0;
  auto f = [&](int i, int j) {
    if ((int)g[i].size() > (int)g[j].size()) swap(i,j);
    double now = 0;
    for(auto v: g[i]) now += cnt[i][v] * cnt[j][v];
    now /= k[i]*k[j];
    return now;
  };

  REP(i,n) for(int j = i+1; j < n; j++) ans = max(ans,f(i,j));
  printf("%.10f\n",ans);
  return 0;
}
