#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<char,int>;

int main() {
  int n; cin >> n;
  string s; cin >> s;

  stack<P> st;
  vector<int> sum(n+1);
  REP(i,n) {
    if (s[i] == '(') st.emplace('(',i);
    if (s[i] == ')' && st.size()) {
      auto [c,idx] = st.top();
      if (c == '(') {
        st.pop();
        sum[idx]++;
        sum[i+1]--;
      }
    }
  }

  REP(i,n) sum[i+1] += sum[i];
  REP(i,n) if (sum[i] == 0) cout << s[i];
  return 0;
}