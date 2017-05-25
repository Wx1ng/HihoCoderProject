#include <iostream>
#include <string>
using namespace std;

//int* get_next(const string s) {
//	int next[10001];
//	next[0] = -1;
//	int i = 0;
//	int q = next[i];
//	while (i < s.length()) {
//		if (q == -1 || s[q] == s[i])
//			next[++i] = ++q;
//		else
//			q = next[q];
//	}
//	return next;
//}

int main() {
	int N;
	cin >> N;
	cin.get();
	while (N--) {
		int Ans = 0;
		string part, ori;
		getline(cin, part);
		getline(cin, ori);
		int next[10001];
		next[0] = -1;
		int p = 0;
		int q = next[p];
		while (p < part.length()) {
			if (q == -1 || part[q] == part[p])
				next[++p] = ++q;
			else
				q = next[q];
		}
		//int* next = get_next(part);
		p = 0, q = 0;
		while (p < ori.length()) {
			if (q == -1 || ori[p] == part[q]) {
				p++; q++;
			}
			else 
				q = next[q];			
			
			if (q == part.length()) {
				Ans++;
		}
		cout << Ans << endl;
	}
	return 0;
}