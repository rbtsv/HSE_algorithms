#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;



template<class T> class MaxPrQueue{
struct CompareSecond{// return x < y
	bool operator()(const std::pair<T, int> &x, const std::pair<T, int> &y){
		if( x.second < y.second ) return true;
		if( x.second > y.second ) return false;
		return x < y;
	}
};
	set<pair<T, int>, CompareSecond> queue;
	map<T, typename set<pair<T, int> >::iterator  > find;
	
	
	public:
		MaxPrQueue(){ };
		void insert(pair<T, int> kv);// main insert
		void insert(T key, int val){ insert(make_pair(key, val));};
		void insert(T key){ insert(make_pair(key, 0)); }; 
		pair<T, int> extract_max();
		void set_priority(pair<T, int> kv);
		void set_priority(T k, int v){ set_priority(make_pair(k,v)); };
		class ExceptionAddTheSameKey{};
};

template<class T>	void MaxPrQueue<T>::insert(pair<T, int> kv){
		if(find.find(kv.first) == find.end() ){				 
				find[kv.first] = queue.insert(kv).first;				
		}else{ throw ExceptionAddTheSameKey(); }
	}
	
template<class T>	pair<T, int> MaxPrQueue<T>::extract_max(){
		typename set<pair<T,int> >::iterator it = queue.end(); //upper_bound(make_pair("Max", max));
		it--;
		find.erase(it->first);
		pair<T,int> x = *it;
		queue.erase(it);
		return x;
	}
	
template<class T>		void MaxPrQueue<T>::set_priority(pair<T, int> kv){	
//		set<pair<T,int> >::iterator it = 
		queue.erase(find[kv.first]);
		find.erase(kv.first);
		insert(kv);
	}
	





int main (int argc, char const *argv[]){
	MaxPrQueue<string> q;
	
	q.insert(make_pair("A", 1));		
	q.insert(make_pair("B", 2));
	q.insert(make_pair("C", 3));
	q.insert(make_pair("D", 1));
	
	
	cout << q.extract_max().first << endl;
	
	q.set_priority("D", 4);
	
	cout << q.extract_max().first << endl;
	cout << q.extract_max().first << endl;
	cout << q.extract_max().first << endl;
	
	return 0;
}
/*set<pair<T, int>, CompareSecond> s;
	
	s.insert(make_pair("A", 1));		
	s.insert(make_pair("B", 2));
	s.insert(make_pair("C", 3));
	s.insert(make_pair("D", 1));
	
	for(set<pair<T, int> >::iterator it = s.begin(); it != s.end(); ++it){
		cout << (*it).first << " " << it->second << endl;
	}
	
	CompareSecond comp;
	cout << "Compare Second:" << comp(make_pair("B", 2),make_pair("A", 1)) << endl;
	
	set<pair<T, int> >::iterator i;
	i = s.upper_bound(make_pair("Z", 3));
	i--;
	cout << "Upper bound: " << i->first << " " << i->second << endl;
*/
