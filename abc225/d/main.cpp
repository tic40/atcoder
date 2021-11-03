#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n,q;
  cin >> n >> q;
  vector<int> top(n,-1),back(n,-1);

  REP(i,q) {
    int t; cin >> t;

    if (t == 1) {
      int x,y; cin >> x >> y;
      x--; y--;

      back[x] = y;
      top[y] = x;
    } else if (t == 2) {
      int x,y; cin >> x >> y;
      x--; y--;

      back[x] = -1;
      top[y] = -1;
    } else {
      int x; cin >> x;
      x--;

      // 最前列の電車を探す
      while(top[x] != -1) x = top[x];

      // 最前列の電車から最後尾まで走査
      vector<int> res;
      while(x != -1) {
        res.push_back(x);
        x = back[x];
      }

      cout << res.size() << " ";
      for(int v: res) cout << v+1 << " ";
      cout << endl;
    }
  }
  return 0;
}