#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n; string s; cin >> n >> s;
  REP(i,n-1) {
    if (s[i] == '1' || s[i+1] == '1') continue;
    cout << -1 << endl;
    return 0;
  }

  mint ans = 0;
  while(s.size() > 1) {
    int c = s.back() - '0';
    s.pop_back();
    // 末尾を消す 1 ターン
    ans += 1;
    // 1 以外の場合は ターン数 * (c - 1) 分の 1 が追加されるのでその分のターン数を加算
    if (c != 1) ans += ans * (c-1);
  }
  cout << ans.val() << endl;
  return 0;
}