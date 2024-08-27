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
  // grundy 数. 0 のとき勝ち
  // grundy[x] := mex(状態 x から到達可能な状態 x' の grundy数の集合). mex = 最小除外数
  vector<int> grundy(m);
  for(int i = 1; i < m; i++) {
    set<int> st;
    for(int v: divs[i]) st.insert(grundy[v]);
    int mex = 0;
    while(st.count(mex)) mex++;
    grundy[i] = mex;
  }

  int n; cin >> n;
  int x = 0;
  REP(i,n) { int a; cin >> a; x ^= grundy[a]; }

  cout << (x == 0 ? "Bruno" : "Anna") << endl;
  return 0;
}