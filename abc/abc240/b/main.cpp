#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n; cin >> n;
  set<int> st;
  REP(i,n) {
    int a; cin >> a;
    st.insert(a);
  }

  cout << st.size() << endl;
  return 0;
}