#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  ll x = 1;
  REP(i,n) x *= 2;
  cout << x << endl;
  return 0;
}
