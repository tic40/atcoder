#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int MOD = 1e9+7;
using mint = modint1000000007;

mint choose(int n, int a) {
  mint x = 1, y = 1;
  REP(i,a) {
    x *= n-i;
    y *= i+1;
  }
  return x / y;
}

int main() {
  ll n,r; cin >> n >> r;
  cout << choose(n,r).val() << endl;
  return 0;
}