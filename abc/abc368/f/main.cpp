#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  const int m = 1e5+1;
  // divs[x] := 非負数 x の自身を除いた約数
  vector divs(m,vector<int>());
  for(int i = 1; i < m; i++) for(int j = i*2; j < m; j+=i) {
    divs[j].push_back(i);
  }
  vector<int> grundy(m);
  for(int i = 1; i < m; i++) {
    set<int> st;
    for(int v: divs[i]) st.insert(grundy[v]);
    while(st.count(grundy[i])) grundy[i]++;
  }

  int n; cin >> n;
  int x = 0;
  REP(i,n) { int a; cin >> a; x ^= grundy[a]; }

  cout << (x == 0 ? "Bruno" : "Anna") << endl;
  return 0;
}