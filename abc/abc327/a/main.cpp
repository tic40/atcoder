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
  string s; cin >> s;
  bool ok = false;
  REP(i,n-1) {
    if (s[i] == 'a' && s[i+1] == 'b') ok = true;
    if (s[i] == 'b' && s[i+1] == 'a') ok = true;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}