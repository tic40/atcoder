#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int q; cin >> q;
  deque<int> dq;
  REP(_,q) {
    int t,x; cin >> t >> x;
    if (t == 1) dq.push_front(x);
    if (t == 2) dq.push_back(x);
    if (t == 3) { x--; cout << dq.at(x) << endl; }
  }
  return 0;
}