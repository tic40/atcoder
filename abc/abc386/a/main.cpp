#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  set<int> st;
  REP(i,4) { int a; cin >> a; st.insert(a); }
  cout << (st.size() == 2 ? "Yes" : "No") << endl;
  return 0;
}