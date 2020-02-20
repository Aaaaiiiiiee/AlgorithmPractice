#include <iostream>
using namespace std;

#define LOCAL

int main(void)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	return 0;
}
