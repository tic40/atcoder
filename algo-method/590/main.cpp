#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n,m;
  cin >> n >> m;
  set<int> st;
  REP(i,n+m) {
    int a; cin >> a;
    st.insert(a);
  }
  for(auto v: st) cout << v << endl;
  return 0;
}