#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> p(n);
  REP(i,n) cin >> p[i];
  vector<int> m(n+1);
  REP(i,n) m[p[i]] = i;
  int q; cin >> q;
  REP(_,q) {
    int a,b; cin >> a >> b;
    int v1 = m[a], v2 = m[b];
    if (v1 > v2) swap(a,b);
    cout << a << endl;
  }
  return 0;
}