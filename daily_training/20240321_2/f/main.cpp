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
  int n; string s;
  cin >> n >> s;
  int t = 0;
  REP(i,n) {
    if (s[i] == '"') t ^= 1;
    if (s[i] == ',' && t == 0) s[i] = '.';
  }
  cout << s << endl;
  return 0;
}