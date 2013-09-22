#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int array[1000000];

long long crossing(int *array, int lo, int hi) {
  if(lo + 1 == hi) return 0;

  int m = (lo + hi) / 2;
  long long result = crossing(array, lo, m) + crossing(array, m, hi);
  for(int i = m; i < hi; i++) {
    result += (array + m) - upper_bound(array + lo, array + m, array[i]);
  }

  sort(array + lo, array + hi);
  return result;
}

int main() {
	int n, a, b, case_num;
	
	case_num = 1;
	
	while((cin>>n>>a>>b)&&!(n==0&&a==0&&b==0)) {	
		memset(array, 0, sizeof(int)*n);
		for(int i = 0; i<n; i++) {
			array[i] = (1ll * a * i + b) % n;
		}

		cout<<"Case "<<case_num<<": "<<crossing(array, 0, n)<<endl;
		
		case_num++;
	}
	return 0;
}

