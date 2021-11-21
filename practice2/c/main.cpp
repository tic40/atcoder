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
  int t;
  cin >> t;
  REP(i,t) {
    ll n,m,a,b;
    cin >> n >> m >> a >> b;
    cout << floor_sum(n,m,a,b) << endl;
  }
  return 0;
}