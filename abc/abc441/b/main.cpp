#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  string s,t; cin >> s >> t;
  vector<int> sm(26),tm(26);
  for(auto c: s) sm[c-'a'] = 1;
  for(auto c: t) tm[c-'a'] = 1;

  int q; cin >> q;
  REP(_,q) {
    string w; cin >> w;
    vector<int> cnt(2);
    for(auto c: w) {
      cnt[0] += sm[c-'a'];
      cnt[1] += tm[c-'a'];
    }
    int bit = 0;
    int ws = w.size();
    if (cnt[0] == ws) bit += 1;
    if (cnt[1] == ws) bit += 2;
    if (bit == 1) cout << "Takahashi" << endl;
    else if (bit == 2) cout << "Aoki" << endl;
    else cout << "Unknown" << endl;
  }
  return 0;
}
