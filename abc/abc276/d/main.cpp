#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  auto f = [&](int x) {
    vector<int> res(4);
    for(int i = 2; i <= 3; i++) {
      int ex = 0;
      while(x%i == 0) { ex++; x/=i; }
      res[i] = ex;
    }
    return res;
  };

  vector<int> mv(4,INF);
  vector<vector<int>> mem(n);
  REP(i,n) {
    mem[i] = f(a[i]);
    mv[2] = min(mv[2],mem[i][2]);
    mv[3] = min(mv[3],mem[i][3]);
  }

  int ans = 0;
  REP(i,n) {
    auto v = mem[i];
    for(int j = 2; j <= 3; j++) {
      int d = v[j] - mv[j];
      a[i] /= pow(j,d);
      ans += d;
    }
  }

  REP(i,n-1) if (a[i] != a[i+1]) ans = -1;
  cout << ans << endl;
  return 0;
}