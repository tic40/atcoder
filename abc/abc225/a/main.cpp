#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

string s;

int f(int n) {
  int res = 1;
  REP(i,n) res *= i+1;
  return res;
}

int main() {
  string s; cin >> s;
  set<char> st;
  for(char c: s) st.insert(c);

  cout << f(3) / f( max(1, 3 - (int)st.size()+1) ) << endl;
  return 0;
}