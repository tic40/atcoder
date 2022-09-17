#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

const vector<P> moves = { {-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1} };

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n);
  map<P,int> mi;
  REP(i,n) {
    cin >> x[i] >> y[i];
    mi[{x[i], y[i]}] = i;
  }

  dsu uf(n);
  map<P,bool> mp;
  REP(i,n) mp[{x[i],y[i]}] = true;

  REP(i,n) for(auto [dx,dy]: moves) {
    int nx = x[i]+dx;
    int ny = y[i]+dy;
    if (mp[{nx,ny}]) uf.merge(i, mi[{nx,ny}]);
  }

  auto g = uf.groups();
  cout << g.size() << endl;
  return 0;
}