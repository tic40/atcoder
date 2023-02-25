#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  stack<P> st;
  auto push = [&](int i, int v) {
    cout << v << " ";
    st.emplace(i,a[i]);
  };

  REP(i,n) {
    int t = -1;
    while(st.size()) {
      auto [x,y] = st.top();
      if (a[i] < y) { t = x+1; break; }
      st.pop();
    }
    push(i,t);
  }

  return 0;
}