#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  unordered_set<int> st;
  for(int i = 1; i <= 2*n+1; i++) st.insert(i);

  while(true) {
    auto it = st.begin();
    cout << *it << endl;
    fflush(stdout);
    st.erase(it);
    int x; cin >> x;
    if (x == 0) break;
    st.erase(x);
  }
  return 0;
}