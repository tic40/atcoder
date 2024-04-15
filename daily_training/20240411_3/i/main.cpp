#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353; // modint1000000007;

int main() {
  string s; cin >> s;
  reverse(s.begin(),s.end());
  int n = s.size();
  mint ans = 0;
  mint c = 1;
  REP(i,n) {
    ans += c * (s[i] - '0');
    c = (c*10 + 1) / 2;
  }
  REP(i,n-1) ans *= 2;
  cout << ans.val() << endl;
  return 0;
}