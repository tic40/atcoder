#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;

  auto f = [&](auto self, int n) -> vector<string> {
    vector<string> res;
    if (n == 0) {
      res.push_back("#");
      return res;
    }
    auto p = self(self,n-1);
    res.assign(p.size()*3, string(p.size()*3,'.'));
    REP(i,3) REP(j,3) {
      if (i == 1 && j == 1) continue;
      REP(x,(int)p.size()) REP(y,(int)p.size()) {
        res[i*p.size()+x][j*p.size()+y] = p[x][y];
      }
    }
    return res;
  };

  for(auto v: f(f,n)) cout << v << endl;
  return 0;
}