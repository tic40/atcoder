#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int N,M,Q;
  cin >> N >> M >> Q;
  vector<int> point(M,N);
  vector<vector<int>> g(N);

  REP(i,Q) {
    int t,n,m;
    cin >> t >> n; n--;
    if (t == 1) {
      int sum = 0;
      for(int v: g[n]) sum += point[v];
      cout << sum << endl;
    } else {
      cin >> m; m--;
      point[m] = max(0, point[m]-1);
      g[n].push_back(m);
    }
  }
  return 0;
}