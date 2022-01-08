#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int x[3];
int main() {
  int a=0;
  string s[3];
  cin>>s[0]>>s[1]>>s[2];
  while(x[a] - s[a].size()) {
    a = s[a][x[a]++]-'a';
  }
  cout << char('A' + a) << endl;
}