#include<iostream>
#include<vector>
using namespace std;
void wavesort(vector<int> &v) {
	//Go to every second element and create a peak
	for (int i = 0; i < v.size(); i += 2) {
		//Check for left element
		if (i > 0 && v[i - 1] > v[i])
			swap(v[i], v[i - 1]);

		//Check for right element
		if (i < v.size() - 1 && v[i + 1] > v[i])
			swap(v[i], v[i + 1]);
	}
}
int main()
{
	vector<int> v{1, 3, 4, 2, 7, 8};
	wavesort(v);
	for (auto it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
}