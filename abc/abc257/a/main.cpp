#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,x; cin >> n >> x;
  string s = "";
  REP(i,26) s += string(n,char('A'+i));
  cout << s[x-1] << endl;
  return 0;
}