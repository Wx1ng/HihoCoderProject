#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int MaxPalindromeSubSequence(const string& s);

int main(){
	int N;
	cin >> N;
	while (N--)
	{
		string s;
		cin >> s;
		string s_toOdd = "#";
		for (int i = 0; i < s.length(); i++){
			s_toOdd += s[i];
			s_toOdd += '#';
		}
		int maxPSS = MaxPalindromeSubSequence(s_toOdd);
		cout << maxPSS << endl;
	}
	return 0;
}

int MaxPalindromeSubSequence(const string& s){
	int maxLength = 0;	//当前最大回文子序列长度
	int pos = 0;		//当前最大回文子序列中心位置
	int maxRight = 0;	//当前已经遍历到的最右值
	vector<int> RL;	//每个pos的回文序列最大值，初始化为0
	for (int i = 0; i < s.length(); i++)
		RL.push_back(0);
	
	for (int i = 0; i < s.length(); i++){
		if (i < maxRight)
			RL[i] = min(RL[2 * pos - i], maxRight - i);
		while (i + RL[i] < s.length() - 1 && i - RL[i] > 0 && s[i + RL[i] + 1] == s[i - RL[i] - 1])
			RL[i] += 1;
		if (i + RL[i]>maxRight){
			pos = i;
			maxRight = i + RL[i];
		}
		maxLength = max(maxLength, RL[i]);
	}
	return maxLength;
}
