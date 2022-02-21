#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n; cin >> n;

  stack<pair<int,int>> st;
  st.push({-1, -1}); // 番人
  int sz = 0;

  REP(i,n) {
    int a; cin >> a;
    sz++;

    auto [prev, num] = st.top();
    if (a == prev) {
      st.pop();
      num++;
      if (a == num) sz -= num;
      else st.push({ a, num });
    } else {
      st.push({ a, 1 });
    }
    cout << sz << endl;
  }

  return 0;
}