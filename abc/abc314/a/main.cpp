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

const string s = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
int main() {
  int n; cin >> n;
  cout << "3.";
  REP(i,n) cout << s[i];
  cout << endl;
  return 0;
}