#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; cin >> n;

  ll x = 1000, ans = 0;
  while(x <= n) {
    ans += n-(x-1);
    x *= 1000;
  }

  cout << ans << endl;
  return 0;
}