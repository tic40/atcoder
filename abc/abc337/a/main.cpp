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
  int n; cin >> n;
  vector<int> x(n),y(n);
  REP(i,n) cin >> x[i] >> y[i];
  int a = accumulate(x.begin(),x.end(),0);
  int b = accumulate(y.begin(),y.end(),0);
  if (a == b) cout << "Draw" << endl;
  if (a > b) cout << "Takahashi" << endl;
  if (a < b) cout << "Aoki" << endl;
  return 0;
}