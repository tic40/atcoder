#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  ll n; cin >> n;
  vector<ll> x(5);
  REP(i,5) cin >> x[i];

  ll mn = *min_element(x.begin(),x.end());
  cout << (n+mn-1)/mn + 4 << endl;

  return 0;
}