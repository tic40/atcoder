#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int sx,sy,tx,ty;
  cin>>sx>>sy>>tx>>ty;
  int dx=tx-sx,dy=ty-sy;
  cout << string(dy,'U') << string(dx,'R');
  cout << string(dy,'D') << string(dx,'L');
  cout << 'L' << string(dy+1,'U') << string(dx+1,'R') << 'D';
  cout << 'R' << string(dy+1,'D') << string(dx+1,'L') << 'U';
  cout << endl;
}