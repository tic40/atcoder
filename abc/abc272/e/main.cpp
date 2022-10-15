#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  // d[0] := 1回目の操作のときの値
  vector<vector<int>> d(m);
  for(int i = 1; i <= n; i++) {
    int a; cin >> a;
    a += i;
    int l = 0 <= a ? 0 : (-a+i-1)/i; // 0を初めて越えるのはいつか
    int r = n <= a ? 0 : (n-a+i-1)/i; // nを初めて越えるのはいつか
    for(int j = l; j < min(m,r); j++) d[j].push_back(a+i*j);
  }

  REP(i,m) {
    // mexを求める
    vector<bool> mex(n+1);
    for(int v: d[i]) mex[v] = true;
    int ans = 0;
    while(mex[ans]) ans++;
    cout << ans << endl;
  }
  return 0;
}