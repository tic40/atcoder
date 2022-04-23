#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,k; cin >> n >> k;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];

  if (k == 1) { cout << "Infinity" << endl; return 0; }

  int ans = 0;
  vector<vector<bool>> used(n,vector<bool>(n));

  REP(i,n) {
    for(int j = i+1; j < n; j++) {
      if (used[i][j]) continue;
      vector<int> list = {i,j};
      int cnt = 2;

      for(int l = j+1; l < n; l++) {
        ll v1 = (x[l] - x[i]) * (y[j] - y[i]);
        ll v2 = (y[l] - y[i]) * (x[j] - x[i]);
        if (v1 == v2) { cnt++; list.push_back(l); }
      }

      for(int l: list) for(int m: list) used[l][m] = true;
      if (k <= cnt) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}