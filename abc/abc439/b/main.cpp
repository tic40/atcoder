#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;

  set<int> st;
  while(1) {
    if (n == 1) { cout << "Yes" << endl; return 0; }
    if (st.count(n)) { cout << "No" << endl; return 0; }
    st.insert(n);

    int x = n;
    int nxt = 0;
    while(x > 0) {
      int a = x % 10;
      nxt += a*a;
      x /= 10;
    }
    n = nxt;
  }

  return 0;
}
