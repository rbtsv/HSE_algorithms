#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> slice(const vector<int> & v, int l, int r){
	if(l >= r) return vector<int>();
	vector<int> res;
	copy(v.begin()+l, v.begin()+r, back_inserter(res)); // v.end() == v.begin() + v.size()
	return res;
}

vector<int> merge(vector<int> a, vector<int> b){
	int i=0, j=0, l, r;
	vector<int> res;
	l = a.size(); r = b.size(); 
	while(i < l and j < r){
		res.push_back( a[i] <= b[j] ? a[i++] : b[j++]);  
	}
	for(; i < l; ++i){
		res.push_back(a[i]);
	}
	for(; j < r; ++j){
		res.push_back(b[j]);
	}
	return res;
}

vector<int> merge_sort(vector<int> v){
	if(v.size() <= 1) return v;
	return merge(merge_sort(slice(v, 0, v.size()/2)),
		 		 merge_sort(slice(v, v.size()/2, v.size() )));
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
		v = merge_sort(v);
		for(size_t j = 0; j < v.size(); ++j){
			cout << v[j] << " ";
		}
		cout << "\n";		
	}
	
	
	return 0;
}
