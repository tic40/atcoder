#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

void generate(int n, int x, int y, vector<vector<char>>& ans) {
  if (n == 0) return;
  int size = pow(3,n-1);
  for (int i = x + size; i < x + 2 * size; i++) {
    for (int j = y + size; j < y + 2 * size; j++) ans[i][j] = '.';
  }

  REP(i,3) REP(j,3) {
    if (i == 1 && j == 1) continue;
    generate(n - 1, x + i * size, y + j * size, ans);
  }
}

int main() {
    int n; cin >> n;
    int size = pow(3,n);
    vector ans(size, vector<char>(size,'#'));
    generate(n,0,0,ans);

    REP(i,size) {
      REP(j,size) cout << ans[i][j];
      cout << endl;
    }
    return 0;
}
