#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

const vector<P> moves = {
  {2,1}, {1,2}, {-1,2}, {-2,1},
  {-2,-1}, {-1,-2}, {1,-2}, {2,-1}
};

int main() {
  int n; int m; cin >> n >> m;
  set<P> st;
  REP(i,m) {
    int a,b; cin >> a >> b; a--; b--;
    st.emplace(a,b);
    for (auto [da,db] : moves) {
      int x = a + da, y = b + db;
      if (x < 0 || y < 0 || x >= n || y >= n) continue;
      st.emplace(x,y);
    }
  }
  cout << (ll)n*n - st.size() << endl;
  return 0;
}