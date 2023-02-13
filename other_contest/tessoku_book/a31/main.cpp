#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; cin >> n;
  ll ans = n/3 + n/5 - n/15;
  cout << ans << endl;
  return 0;
}