#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  REP(i,n) a[i] %= 200;

  int bn = min(n,8);
  vector<int> m(200);
  REP(bit,1<<bn) {
    int now = 0;
    REP(i,bn) if (bit >> i & 1) now += a[i];
    now %= 200;
    if (m[now] == 0) { m[now] = bit; continue; }

    vector<int> b,c;
    REP(j,bn) if (m[now] >> j & 1) b.push_back(j+1);
    REP(j,bn) if (bit >> j & 1) c.push_back(j+1);

    cout << "Yes" << endl;
    cout << b.size() << " ";
    for(int v: b) cout << v << " ";
    cout << endl;
    cout << c.size() << " ";
    for(int v: c) cout << v << " ";
    cout << endl;
    return 0;
  }

  cout << "No" << endl;
  return 0;
}