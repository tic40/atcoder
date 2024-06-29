#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353; // modint1000000007;

auto is_palindrome(string s) {
  string t = s;
  reverse(t.begin(),t.end());
  return t == s;
}

int main() {
  int n,k; cin >> n >> k;
  string s; cin >> s;
  // dp[i][t] := i まで決めて直前 k-1 文字が t である
  map<string,mint> dp;
  dp[""] = 1;

  REP(i,n) {
    map<string,mint> old;
    swap(dp,old);
    for(char c = 'A'; c <= 'B'; c++) if (s[i] == '?' || c == s[i]) {
      for(auto [t,num]: old) {
        string nt = t + c;
        if ((int)nt.size() == k && is_palindrome(nt)) continue;
        if ((int)nt.size() == k) nt.erase(nt.begin());
        dp[nt] += num;
      }
    }
  }

  mint ans = 0;
  for(auto [_,num]: dp) ans += num;
  cout << ans.val() << endl;
  return 0;
}