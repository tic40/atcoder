#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  string s;
  int k;
  cin >> s >> k;

  int n = s.size();
  set<string> st;
  REP(i,n) {
    for(int j = 1; j <= min(k, n-i); j++) {
      st.insert(s.substr(i, j));
    }
  }

  auto it = st.begin();
  advance(it, k-1);
  cout << *it << endl;
  return 0;
}