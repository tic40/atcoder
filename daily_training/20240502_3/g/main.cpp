#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int t; cin >> t;
  REP(i,t) {
    ll a,s; cin >> a >> s;
    ll d = s - a;
    bool ok = d >= 0 && (a & d) == a;
    cout << (ok ? "Yes" : "No") << endl;
  }
  return 0;
}