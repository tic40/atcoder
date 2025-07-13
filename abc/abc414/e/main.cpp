#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353;

int main() {
  ll n; cin >> n;
  // a > b の総数
  // ここから a % b == 0 のケースを引く
  mint ans = mint(n+1)*n/2;
  ll b = 1;
  while(b <= n) {
    ll y = n/b;
    ll nb = n/y+1;
    ans -= mint(nb-b)*y;
    b = nb;
  }
  cout << ans.val() << endl;
  return 0;
}