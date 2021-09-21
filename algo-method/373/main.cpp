#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,m;
  cin >> n >> m;
  vector<bool> num(101);
  REP(i,n) {
    int a; cin >> a;
    num[a] = true;
  }
  set<int> st;
  REP(i,m) {
    int b; cin >> b;
    if (num[b]) st.insert(b);
  }

  for(int v: st) cout << v << " ";
  return 0;
}