#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  ll a,b; cin >> a >> b;
  ll d = gcd(a,b);
  if (a/d > (ll)1e18/b) cout << "Large" << endl;
  else cout << a/d*b << endl;
  return 0;
}