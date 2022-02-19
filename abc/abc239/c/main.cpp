#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;
using P = pair<int,int>;

int main() {
  ll x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;

  x2 -= x1;
  y2 -= y1;
  x1 = 0;
  y1 = 0;

  x2 = abs(x2);
  y2 = abs(y2);

  for(ll i = -5; i <= 5; i++) {
    for(ll j = -5; j <= 5; j++) {
      ll cur = i*i+j*j;
      if (cur == 5) {
        ll d = (i-x2) * (i-x2) + (j-y2) * (j-y2);
        if (d == 5) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;
  return 0;
}