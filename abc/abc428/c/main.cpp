#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int q; cin >> q;
  stack<char> st;
  int cnt = 0;
  int p = 1e9;
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      char c; cin >> c;
      st.push(c);
      c == '(' ? cnt++ : cnt--;
    } else {
      st.top() == '(' ? cnt-- : cnt++;
      st.pop();
    }
    if (cnt == -1) p = min(p, (int)st.size());

    if (p <= (int)st.size()) {
      cout << "No" << endl;
    } else {
      p = 1e9;
      cout << (cnt == 0 ? "Yes" : "No") << endl;
    }
  }
  return 0;
}