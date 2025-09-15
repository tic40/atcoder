#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll x,c; cin >> x >> c;
  // x >= a + a/1000c;
  // 1000x >= 1000a + ac;
  // 1000x >= a(1000 + c)
  // a <= (1000x) / (1000+c)

  cout << (1000 * x) / (1000+c) / 1000 * 1000 << endl;
  return 0;
}