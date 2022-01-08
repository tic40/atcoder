#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  cout << (b-a == c-b ? "YES" : "NO") << endl;
  return 0;
}