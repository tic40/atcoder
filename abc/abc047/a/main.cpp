#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  cout << ( (a+b==c)||(a+c==b)||(b+c==a) ? "Yes" : "No") << endl;
}