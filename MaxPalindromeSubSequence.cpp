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
	int maxLength = 0;	//��ǰ�����������г���
	int pos = 0;		//��ǰ����������������λ��
	int maxRight = 0;	//��ǰ�Ѿ�������������ֵ
	vector<int> RL;	//ÿ��pos�Ļ����������ֵ����ʼ��Ϊ0
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
