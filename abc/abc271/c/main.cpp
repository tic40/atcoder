#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  unordered_set<int> st;
  REP(i,n) {
    int a; cin >> a;
    st.insert(a);
  }

  int s = 0;
  for(int i = 1; i <= n+1; i++) {
    if (st.count(i)) s++;
    else s+=2;
    if (n < s) { cout << i-1 << endl; return 0; }
  }
  return 0;
}