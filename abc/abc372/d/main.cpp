#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  vector<int> ans(n);
  vector<int> st;
  for(int i = n-1; i >= 0; i--) {
    ans[i] = st.size();
    // 現在のビルが stack のトップより高い場合
    // stack のトップにあるビルは数え上げ対象にならないため pop する
    while(st.size() && h[st.back()] < h[i]) st.pop_back();
    st.push_back(i);
  }

  for(auto v: ans) cout << v << " ";
  return 0;
}