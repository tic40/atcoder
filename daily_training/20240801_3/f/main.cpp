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
  int n,k; cin >> n >> k;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  int ans = 0;
  REP(bit,1<<n) {
    vector<int> t(26);
    REP(i,n) if (bit >> i & 1) {
      for(auto c: s[i]) t[c-'a']++;
    }
    int now = 0;
    REP(i,26) if (t[i] == k) now++;
    ans = max(ans,now);
  }
  cout << ans << endl;
  return 0;
}