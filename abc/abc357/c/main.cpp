#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

vector<string> f(int n) {
  if (n == 0) return { "#" };
  auto p = f(n-1);
  int psize = p.size();
  vector<string> res(psize*3,string(psize*3,'.'));

  REP(i,3) REP(j,3) if (i != 1 || j != 1) {
    REP(x,psize) REP(y,psize) {
      res[i*psize+x][j*psize+y] = p[x][y];
    }
  }
  return res;
}

int main() {
  int n; cin >> n;
  for(auto s: f(n)) cout << s << endl;
  return 0;
}