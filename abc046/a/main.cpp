#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int a,b,c,ans = 1;
  cin>>a>>b>>c;
  if (b!=a) ans++;
  if (c!=a && c!=b) ans++;
  cout << ans << endl;
}