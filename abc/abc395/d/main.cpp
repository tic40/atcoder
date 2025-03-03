#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  // p:鳩, h:巣, b:袋
  vector<int> p2b(n); // 鳩->袋, p2b[i] := 鳩iの袋番号
  vector<int> b2h(n); // 袋->巣, b2h[i] := 袋iの巣番号
  vector<int> h2b(n); // 巣->袋, h2b[i] := 巣iの袋番号
  REP(i,n) p2b[i] = i, b2h[i] = i, h2b[i] = i;

  while(q--) {
    int t,a,b; cin >> t >> a; a--;
    if (t == 1) {
      cin >> b; b--;
      p2b[a] = h2b[b];
    }
    if (t == 2) {
      cin >> b; b--;
      swap(h2b[a],h2b[b]);
      swap(b2h[h2b[a]],b2h[h2b[b]]);
    }
    if (t == 3) cout << b2h[p2b[a]]+1 << endl;
  }
  return 0;
}
