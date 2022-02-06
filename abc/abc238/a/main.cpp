#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  ll n;
  cin >> n;
  if (n <= 10) {
    ll a = 2;
    REP(i,n-1) a*=2;
    cout << (a > n*n ? "Yes" : "No") << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}