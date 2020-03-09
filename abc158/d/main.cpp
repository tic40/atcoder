#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  string s; cin >> s;
  int q; cin >> q;
  int t,f;
  char c;
  string _head, _tail=s;

  REP(i,q) {
    cin >> t;
    if (t==1) { swap(_head,_tail); continue; }
    cin >> f >> c;
    if (f==1) _head.push_back(c);
    else _tail.push_back(c);
  }
  reverse(_head.begin(),_head.end());
  string ans = _head + _tail;
  cout << ans << endl;
  return 0;
}