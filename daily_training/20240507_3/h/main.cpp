#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector<P> v(2*n, {-1,-1});
  REP(i,n) {
    int a,b; cin >> a >> b;
    a--; b--;
    if (a > b) swap(a,b);
    v[a] = {0,i};
    v[b] = {1,i};
  }

  stack<P> st;
  REP(i,2*n) {
    auto [t,id] = v[i];
    if (t == -1) continue;
    if (t == 0) st.push({t,id});
    if (t == 1) {
      if (st.top().second == id) {
        st.pop();
      } else {
        cout << "Yes" << endl; return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}