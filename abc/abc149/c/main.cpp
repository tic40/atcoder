#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

bool isPrime(int num){
  bool flag=true;
  for(int i = 2; i <= num / 2; i++) {
    if(num % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}
int main() {
  int x;
  cin >> x;
  while(true) {
      if(isPrime(x)) { cout << x << endl; return 0; }
      x++;
  }
}
