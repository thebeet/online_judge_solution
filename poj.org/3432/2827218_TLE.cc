#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> vet;
map<vet, bool> hash;

vet vets[2048];

int main()
{
	int i, j, n;
	int sum(0);
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		cin >> vets[i].first >> vets[i].second;
		hash[vets[i]] = true;
	}
	
	for (i = 1; i <= n; ++i)
	{
		for (j = i + 1; j <= n; ++j)
		{
			vet vet1, vet2;
			vet1.first = vets[i].first + (vets[i].second - vets[j].second);
			vet1.second = vets[i].second - (vets[i].first - vets[j].first);
			vet2.first = vets[j].first + (vets[i].second - vets[j].second);
			vet2.second = vets[j].second - (vets[i].first - vets[j].first);
			if (hash[vet1] && hash[vet2])
			{
				++sum;
			}
			vet1.first = vets[i].first - (vets[i].second - vets[j].second);
			vet1.second = vets[i].second + (vets[i].first - vets[j].first);
			vet2.first = vets[j].first - (vets[i].second - vets[j].second);
			vet2.second = vets[j].second + (vets[i].first - vets[j].first);
			if (hash[vet1] && hash[vet2])
			{
				++sum;
			}
		}
	}
	cout << (sum >> 2) << endl;
	return 0;
}
