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
  vector<int> d;
  for(int i = 1; i <= 9; i++) {
    if (n % i == 0) d.push_back(i);
  }
  REP(i,n+1) {
    string c = "-";
    for(auto j: d) {
      if (i % (n/j) == 0) { c = j + '0'; break; }
    }
    cout << c;
  }
  return 0;
}