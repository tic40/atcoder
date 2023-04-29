#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector<string> a(h), b(h);
  REP(i,h) cin >> a[i];
  REP(i,h) cin >> b[i];

  bool ok = false;
  REP(i,h) {
    if (a == b) ok = true;
    REP(k,h-1) swap(a[k],a[k+1 >= h ? 0 : k+1]);
    REP(j,w) {
      REP(k,h) rotate(a[k].rbegin(), a[k].rbegin()+1, a[k].rend());
      if (a == b) ok = true;
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}