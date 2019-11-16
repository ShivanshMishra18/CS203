#include <bits/stdc++.h>
using namespace std;

class HashTable
{
	int slots;
	list <int> *slotlist;

public:

	HashTable(int s) {
		slots = s;
		slotlist = new list<int>[s];
	}

	~HashTable() {
		delete[] slotlist;
	}

	int HashValue(int x) {
		return (x % slots);
	}

	void Insert(int x) {
		slotlist[HashValue(x)].push_front(x);
	}

	bool Search(int x) {
		int s_idx = HashValue(x);
		for (int val : slotlist[s_idx])
			if (val == x)
				return true;

		return false; 
	}

	void Delete(int x) {
		int s_idx = HashValue(x);

		auto it = slotlist[s_idx].begin();
		for (it = slotlist[s_idx].begin(); it != slotlist[s_idx].end(); it++)
			if (*it == x)
				break;

		if (it != slotlist[s_idx].end())
			slotlist[s_idx].erase(it);
	}

	void ShowHashTable() {
		for (int i=0; i<slots; i++)
		{
			cout << "Slot " << i << " contents:";
			for (auto x : slotlist[i])
				cout << " "<< x << " ";
			cout << "\n";
		}
	}
};

int main()
{
	int n, k;
	cin >> n;

	HashTable H(n);

	do
	{
		cin >> k;

		if (k==1) {
			int x; cin >> x;
			H.Insert(x);
		}
		else if (k==2) {
			int x; cin >> x;
			H.Delete(x);
		}
		else if (k==3) {
			int x; cin >> x;
			if (H.Search(x))
				 cout << "Found\n";
			else cout << "Not Found\n";
		}
		else if (k==4) {
			H.ShowHashTable();
		}
	} 
	while (k);

	return 0;
}