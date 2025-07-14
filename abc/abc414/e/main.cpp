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
  // ∑(n-b - (⌊n/b⌋-1)) を求めればよい // ∑は b=1 to n
  //   ∑(n-b+1) = n,n-1,n-2...1 の等差数列 = (n+1)*n/2
  // ここから a % b == 0 のケースを引いていく
  mint ans = mint(n+1)*n/2;
  ll b = 1;
  // 商列挙テクニック
  while(b <= n) {
    ll y = n/b;
    ll nb = n/y+1;
    ans -= mint(nb-b)*y;
    b = nb;
  }
  cout << ans.val() << endl;
  return 0;
}