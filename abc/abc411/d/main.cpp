#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<tuple<int,int,string>> e;
  REP(i,q) {
    int t,p; string s;
    cin >> t >> p; p--;
    if (t == 2) { cin >> s; reverse(s.begin(),s.end()); }
    e.emplace_back(t,p,s);
  }
  reverse(e.begin(),e.end());

  string ans = "";
  int si = -1; // サーバー文字列となっている pc 番号
  for(auto [t,p,s]: e) {
    // pc[p] をサーバー文字列にする
    if (t == 1) { if (si == p) si = -1; }
    // pc[p] の末尾に s 追加
    if (t == 2) { if (si == p) ans += s; }
    // サーバー文字列を pc[p] にする
    if (t == 3) { if (si == -1) si = p; }
    cout << si << " " << ans << endl;
  }

  reverse(ans.begin(),ans.end());
  cout << ans << endl;
  return 0;
}