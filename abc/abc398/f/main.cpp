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
  string s; cin >> s;
  int n = s.size();
  if (n == 1) { cout << s << endl; return 0; }

  auto f = [&](string& s) {
    int n = s.size();
    vector<int> pi(n);
    for(int i = 1; i < n; i++) {
      int j = pi[i-1];
      while(j > 0 && s[i] != s[j]) j = pi[j-1];
      if (s[i] == s[j]) j++;
      pi[i] = j;
    }
    return pi;
  };

  auto sr = s;
  reverse(sr.begin(),sr.end());
  auto t = sr + "_" + s;
  auto pi = f(t);
  int r = pi[t.size()-1];
  auto ans = s;
  auto add = s.substr(0,n-r);
  reverse(add.begin(),add.end());
  ans += add;
  cout << ans << endl;
  return 0;
}
