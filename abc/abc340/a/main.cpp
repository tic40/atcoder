#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int a,b,c; cin >> a >> b >> c;
  while(a <= b) { cout << a << " "; a += c; }
  return 0;
}