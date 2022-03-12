#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int n;
ll x;
string s;

void solve() {
  deque<char> st;
  REP(i,n) {
    if (st.empty()) {
      st.push_back(s[i]);
      continue;
    }

    char top = st.back();
    if (s[i] == 'U' && top != 'U') st.pop_back();
    else st.push_back(s[i]);
  }

  vector<char> vs;
  while(st.size()) {
    char t = st.front();
    st.pop_front();

    if (t == 'U') x/=2;
    else if (t == 'L') x*=2;
    else if (t == 'R') x = x*2+1;
  }

  cout << x << endl;
  return;
}

int main() {
  cin >> n >> x >> s;
  solve();
  return 0;
}