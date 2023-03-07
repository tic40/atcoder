#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int q; cin >> q;
  // dq1: 前半半分, dq2: 後半半分
  deque<string> dq1,dq2;
  REP(_,q) {
    char t; cin >> t;

    if (t == 'A') { string x; cin >> x; dq2.push_back(x); }
    if (t == 'B') { string x; cin >> x; dq1.push_back(x); }
    if (t == 'C') dq1.pop_front();
    if (t == 'D') cout << dq1.front() << endl;

    int diff = dq1.size() - dq2.size();
    if (diff < 0) {
      dq1.push_back(dq2.front());
      dq2.pop_front();
    } else if (diff > 1) {
      dq2.push_front(dq1.back());
      dq1.pop_back();
    }
  }
  return 0;
}