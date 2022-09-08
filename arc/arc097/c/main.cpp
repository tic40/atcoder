#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  string s; int k;
  cin >> s >> k;
  int n = s.size();

  set<string> st;
  REP(i,n) REP(j, min(k,n-i)) {
    st.insert(s.substr(i,j+1));
  }

  int i = 0;
  for(auto v: st) {
    if (i == k-1) { cout << v << endl; return 0; }
    i++;
  }

  return 0;
}