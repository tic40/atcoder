#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int a,b; cin >> a >> b;
  a--; b--;
  vector x(3, vector<int>(3));
  x[a/3][a%3] = 1;
  x[b/3][b%3] = 1;
  bool ok = false;
  REP(i,3) REP(j,2) if (x[i][j] && x[i][j+1]) ok = true;
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}