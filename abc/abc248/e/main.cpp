#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;

bool colinear(P i, P j, P k) {
  auto [x1,y1] = i;
  auto [x2,y2] = j;
  auto [x3,y3] = k;
  // (x2 - x1) / (y2 - y1) = (x3 - x1) / (y3 - y1)
  ll v1 = (y2 - y1) * (x3 - x1);
  ll v2 = (x2 - x1) * (y3 - y1);
  return v1 == v2;
}

int main() {
  int n,k; cin >> n >> k;
  vector<P> p(n);
  REP(i,n) {
    int x,y; cin >> x >> y;
    p[i] = {x,y};
  }

  if (k == 1) { cout << "Infinity" << endl; return 0; }

  vector<vector<bool>> flag(n, vector<bool>(n));
  int ans = 0;

  REP(i,n) for(int j = i+1; j < n; j++) {
    if (flag[i][j]) continue;
    int cnt = 2;
    vector<int> list = {i,j};
    for (int l = j + 1; l < n; l++) {
      if (colinear(p[i],p[j],p[l])) {
        cnt++;
        list.push_back(l);
      }
    }

    REP(l, cnt) for (int m = l + 1; m < cnt; m++) {
      flag[list[l]][list[m]] = true;
    }

    if (k <= cnt) ans++;
  }
  cout << ans << endl;
  return 0;
}