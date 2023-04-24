#include <bits/stdc++.h>
using namespace std;

set<int> s;
int main()
{
	int n = 10;
	while(n--)
	{
		s.insert(2);
		s.insert(3);
	}
	cout << s.count(2) << " " << s.count(1) << endl;
	
	return 0;
}
