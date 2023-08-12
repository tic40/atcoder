#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> m(1e5+1);
  ll tot = 0;
  REP(i,n) {
    int a; cin >> a;
    m[a]++;
    tot += a;
  }
  int q; cin >> q;
  REP(i,q) {
    int b,c; cin >> b >> c;
    tot += (c - b) * m[b];
    m[c] += m[b];
    m[b] = 0;
    cout << tot << endl;
  }
  return 0;
}