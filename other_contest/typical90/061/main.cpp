#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int q; cin >> q;
  deque<int> dq;
  REP(_,q) {
    int t,x;
    cin >> t >> x;
    if (t == 1) {
      dq.push_front(x);
    } else if (t == 2) {
      dq.push_back(x);
    } else {
      cout << dq.at(x-1) << endl;
    }
  }
  return 0;
}