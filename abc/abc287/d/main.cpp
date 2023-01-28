#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  int ns = s.size(), ts = t.size();

  unordered_set<int> st;
  auto match = [&](char a, char b) { return a == '?' || b == '?' || a == b; };
  auto out = [&]() { cout << (st.size() ? "No" : "Yes") << endl; };

  REP(i,ts) if (!match(s[ns-ts+i], t[i])) st.insert(i);
  out();

  REP(i,ts) {
    if (!match(s[i], t[i])) st.insert(i);
    else st.erase(i);

    out();
  }

  return 0;
}