#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> k(n);
  vector cnt(n,vector<int>(1e5+1));
  vector g(n,vector<int>());
  REP(i,n) {
    cin >> k[i];
    REP(_,k[i]) {
      int x; cin >> x;
      cnt[i][x]++;
      if (cnt[i][x] == 1) g[i].push_back(x);
    }
  }

  double ans = 0.0;
  REP(i,n) for(int j = i+1; j < n; j++) {
    double now = 0.0;
    for(auto v: g[i]) now += ((double)cnt[i][v] / k[i]) * ((double)cnt[j][v] / k[j]);
    ans = max(ans,now);
  }

  printf("%.10f\n",ans);
  return 0;
}
