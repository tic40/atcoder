#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = unsigned long long;

int main() {
  ll ans = 0;
  REP(i,64) {
    int b; cin >> b;
    if (b == 1) ans += (1LL<<i);
  }
  cout << ans << endl;
  return 0;
}