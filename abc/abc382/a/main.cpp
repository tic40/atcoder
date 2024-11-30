#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,d; string s;
  cin >> n >> d >> s;
  for(auto c: s) if (c == '@') n--;
  cout << n+d << endl;
  return 0;
}