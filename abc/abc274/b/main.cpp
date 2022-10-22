#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector<string> c(h);
  REP(i,h) cin >> c[i];

  REP(j,w) {
    int x = 0;
    REP(i,h) { if (c[i][j] == '#') x++; }
    cout << x << " ";
  }
  cout << endl;
  return 0;
}