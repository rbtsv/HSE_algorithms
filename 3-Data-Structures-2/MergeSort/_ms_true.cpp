#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void merge(vector<int> & v, int la, int ra, int lb, int rb){	
	vector<int> res;
	int i = la, j = lb;	
	while(i < ra and j < rb){
		res.push_back( v[i] <= v[j] ? v[i++] : v[j++]);  
	}
	for(; i < ra; ++i){
		res.push_back(v[i]);
	}
	for(; j < rb; ++j)
		res.push_back(v[j]);	
	copy(res.begin(), res.end(), v.begin()+la);
}

void merge_sort(vector<int> & v, int l, int r ){
	if(r-l <= 1) return;
	int m = (l+r)/2;
	merge_sort(v, l, m);
	merge_sort(v, m, r);
	merge(v, l, m, m, r);
}


int main (int argc, char const *argv[]){
	std::ios::sync_with_stdio(false); std::cin.tie(0);
	//freopen("tsort", "r", stdin);
	int t = 0;
	cin >> t;
	for(size_t i = 0; i < t; ++i){
		int n;
		cin >> n;		
		vector <int> v(n,0), vv;

		for(size_t j = 0; j < n; ++j){
			cin >> v[j];
		}
		//sort(v.begin(), v.end());	
		//vv = slice(v, 0, v.size());
		//vv = merge(vv, v);
		merge_sort(v, 0, v.size());
		for(size_t j = 0; j < v.size(); ++j){
			cout << v[j] << " ";
		}
		cout << "\n";		
	}
	
	
	return 0;
}
