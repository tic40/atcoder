#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n; string s;
  cin >> n >> s;

  ll ans = 0;
  REP(i,n) ans += (1LL<<i)*(s[i]-'a');
  cout << ans << endl;
  return 0;
}