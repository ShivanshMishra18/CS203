#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<string> fw, bw;
	string s;

	for (int i=0; i<n; i++)
	{
		cin >> s;
		string srev = s;
		reverse(srev.begin(), srev.end());
		if (s!=srev) {
			fw.push_back(s);
			bw.push_back(srev);
		}
	}

	sort(fw.begin(), fw.end());

	for (auto str: bw)
	{
		if (binary_search(fw.begin(), fw.end(), str))
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
