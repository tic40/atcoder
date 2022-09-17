#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  const int n = 10;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  int a = 1e9, b = -1;
  int c = 1e9, d = -1;
  REP(i,n) REP(j,n) {
    if (s[i][j] == '.') continue;
    a = min(a,i);
    b = max(b,i);
    c = min(c,j);
    d = max(d,j);
  }
  cout << a+1 << " " << b+1 << endl;
  cout << c+1 << " " << d+1 << endl;
  return 0;
}