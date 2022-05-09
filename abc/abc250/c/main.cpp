#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,q; cin >> n >> q;
  vector<int> s(n), pos(n);
  REP(i,n) s[i] = i;
  REP(i,n) pos[i] = i;

  REP(i,q) {
    int x; cin >> x;
    x--;
    int idx = pos[x];
    int nidx = (idx == n-1) ? idx-1 : idx+1;

    swap(s[idx], s[nidx]);
    swap(pos[s[idx]], pos[s[nidx]]);
  }

  REP(i,n) cout << s[i]+1 << " ";
  cout << endl;
  return 0;
}
