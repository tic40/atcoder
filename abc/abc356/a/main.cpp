#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

int main() {
  int n,l,r;
  cin >> n >> l >> r;
  for(int i = 1; i < l; i++) cout << i << " ";
  for(int i = r; i >= l; i--) cout << i << " ";
  for(int i = r+1; i <= n; i++) cout << i << " ";
  return 0;
}