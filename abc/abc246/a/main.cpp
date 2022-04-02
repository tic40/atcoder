#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int x,y;
  map<int,int> mx,my;
  REP(i,3) {
    cin >> x >> y;
    mx[x]++; my[y]++;
  }
  int ax,ay;
  for(auto [s,t]: mx) if (t == 1) ax = s;
  for(auto [s,t]: my) if (t == 1) ay = s;
  cout << ax << " " << ay << endl;

  return 0;
}