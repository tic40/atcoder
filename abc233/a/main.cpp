#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int x,y; cin >> x >> y;
  int d = y - x;
  if (0 < d) cout << (d+9) / 10 << endl;
  else cout << 0 << endl;

  return 0;
}