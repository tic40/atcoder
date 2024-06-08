#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

void f(int n, int x, int y, vector<vector<char>>& ans) {
  if (n == 0) return;
  int size = pow(3,n-1);
  REP(i,size) REP(j,size) ans[x+i+size][y+j+size] = '.';

  REP(i,3) REP(j,3) if (i != 1 || j != 1) {
    f(n-1, x+i*size, y+j*size, ans);
  }
}

int main() {
    int n; cin >> n;
    int size = pow(3,n);
    vector ans(size, vector<char>(size,'#'));
    f(n,0,0,ans);

    REP(i,size) {
      REP(j,size) cout << ans[i][j];
      cout << endl;
    }
    return 0;
}