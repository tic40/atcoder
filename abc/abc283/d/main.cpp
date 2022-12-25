#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();

  vector<bool> a(26);
  stack<char> st;
  REP(i,n) {
    if (s[i] == '(') {
      st.push(s[i]);
    } else if (s[i] == ')') {
      int cnt = 1;
      while(st.size()) {
        char v = st.top(); st.pop();
        if (v == '(') cnt--;
        else if (v == ')') cnt++;
        else a[ v-'a' ] = false;

        if (cnt == 0) break;
      }
    } else {
      st.push(s[i]);
      if (a[ s[i]-'a' ]) { cout << "No" << endl; return 0; }
      a[ s[i]-'a' ] = true;
    }
  }

  cout << "Yes" << endl;
  return 0;
}