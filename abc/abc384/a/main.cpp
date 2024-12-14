#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; char c1,c2; string s;
  cin >> n >> c1 >> c2 >> s;
  for(auto c: s) cout << (c == c1 ? c : c2);
  return 0;
}