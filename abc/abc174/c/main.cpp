#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int k; cin >> k;

  int x = 7;
  REP(i,1e6) {
    if (x % k == 0) {
      cout << i+1 << endl; return 0;
    }
    x %= k;
    x = x*10 + 7;
  }

  cout << -1 << endl;
  return 0;
}