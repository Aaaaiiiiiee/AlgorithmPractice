#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LOCAL

// S : 수열 S.	result : 탐색 과정의 부분수열
vector<int> S, result;
/*
   int LIS(const int& n)
   *	완전탐색
   *	const int& n : 현재까지 탐색한 수열 S의 index
 */
int LIS(const int& n);

int main(void)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int C;	cin >> C;
	while(C--)
	{
		// Init Data
		int N;	cin >> N;
		while(N--)
		{
			int input;	cin >> input;
			S.push_back(input);
		}
		result.push_back(0);

		// Print Searched Result
		cout << LIS(0) << endl;

		S.clear();	result.clear();
	}

	return 0;
}

int LIS(const int& n)
{
	// 기저사례 : 수열 S의 마지막에 도달했을 때
	if(n == S.size())
		return result.size() - 1;

	// Calculate Answer
	int max_size = -1;
	// 부분수열의 마지막 수보다, 현재 탐색 중인 수열 S의 값이 더 크면
	if(result[result.size() - 1] < S[n])
	{
		result.push_back(S[n]);
		max_size = LIS(n + 1);
		result.pop_back();
	}
	// 현재 탐색 중인 수열 S를 안 넣는 경우
	max_size = max(max_size, LIS(n + 1));

	return max_size;
}
