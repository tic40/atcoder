#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint1000000007;

const string acgt = "ACGT";
bool match(string& a) { return regex_search(a,regex("AGC")); };
bool possible(string& b) {
  if (b.size() < 3) return true;
  if (match(b)) return false;
  REP(j,(int)b.size()-1) {
    swap(b[j],b[j+1]);
    if (match(b)) return false;
    swap(b[j],b[j+1]);
  }
  return true;
};

int main() {
  int n; cin >> n;
  vector dp(n+1, map<string,mint>());
  dp[0][""] = 1;

  REP(i,n) for(auto [a,cnt]: dp[i]) for(auto c: acgt) {
    auto b = a + c;
    if (possible(b)) dp[i+1][b.size() > 3 ? b.substr(1,3) : b] += dp[i][a];
  }

  mint ans = 0;
  for(auto [_,k]: dp[n]) ans += k;
  cout << ans.val() << endl;
  return 0;
}