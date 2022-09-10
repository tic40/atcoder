#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  set<int> st;
  REP(i,5) { int a; cin >> a; st.insert(a); }
  cout << st.size() << endl;
  return 0;
}