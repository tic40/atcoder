#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int q; cin >> q;
  stack<string> st;
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      string x; cin >> x;
      st.push(x);
    } else if (t == 2) {
      cout << st.top() << endl;
    } else {
      st.pop();
    }
  }
  return 0;
}