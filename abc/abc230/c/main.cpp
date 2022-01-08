#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

ll n,a,b,p,q,r,s;

int main() {
  cin >> n >> a >> b;
  cin >> p >> q >> r >> s;

  for(ll i = p; i <= q; i++) {
    for(ll j = r; j <= s; j++) {
      if ( (i-j) == (a-b) ) cout << "#";
      else if ( (i+j) == (a+b) ) cout << "#";
      else cout << ".";

    }
    cout << endl;
  }

  return 0;
}