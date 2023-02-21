#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();
  stack<int> st;
  REP(i,n) {
    if (st.empty() || s[i] == '(') {
      st.push(i);
    } else  {
      cout << st.top()+1 << " " << i+1 << endl;
      st.pop();
    }
  }
  return 0;
}