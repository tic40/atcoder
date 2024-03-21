#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

const vector<P> moves = { {-1,-1}, {-1,0}, {0,-1}, {0,1}, {1,0}, {1,1} };

int main() {
  int n; cin >> n;
  vector g(2005, vector<int>(2005));
  vector<int> x(n),y(n);
  REP(i,n) {
    cin >> x[i] >> y[i];
    x[i]+=1000; y[i]+=1000;
    g[x[i]][y[i]] = 1;
  }

  auto h = [&](int a, int b) { return a*2000+b; };
  dsu uf(2000*2001+5);
  REP(i,n) {
    int a = x[i];
    int b = y[i];
    for(auto [da,db]: moves) {
      int na = a + da;
      int nb = b + db;
      if (na < 0 || nb < 0 || na > 2000 || nb > 2000) continue;
      if (g[na][nb] == 1) uf.merge(h(a,b), h(na,nb));
    }
  }

  unordered_set<int> st;
  REP(i,n) st.insert(uf.leader(h(x[i],y[i])));
  cout << st.size() << endl;
  return 0;
}