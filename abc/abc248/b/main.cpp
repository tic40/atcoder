#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  ll a,b,k; cin >> a >> b >> k;
  int ans = 0;
  while(a < b) { ans++; a *= k; }
  cout << ans << endl;
  return 0;
}