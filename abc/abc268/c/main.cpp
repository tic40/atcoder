#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> cost(n);
  REP(i,n) {
    int p; cin >> p;
    int d = (p - i - 1 + n) % n;
    cost[d]++;
    cost[(d+1)%n]++;
    cost[(d+2)%n]++;
  }

  cout << *max_element(cost.begin(),cost.end()) << endl;
  return 0;
}