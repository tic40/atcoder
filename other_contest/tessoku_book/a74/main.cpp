#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n);
  REP(i,n) REP(j,n) {
    int p; cin >> p;
    if (p == 0) continue;
    p--;
    x[i] = p; y[j] = p;
  }

  auto f = [](vector<int>& v) {
    int res = 0, n = v.size();
    fenwick_tree<int> fw(n);
    REP(i,n) {
      fw.add(v[i],1);
      res += fw.sum(v[i]+1,n);
    }
    return res;
  };

  int ans = f(x) + f(y);
  cout << ans << endl;
  return 0;
}