#include<iostream>

namespace One{
    struct int_pair{
        int first;
        int second;
    };
}

namespace Two{
    struct int_pair{
        bool flag;
        int first;
        int second;
    };
}


using std::cout, std::endl;

using namespace Two; 

int main (int argc, char const *argv[]){		    
    int_pair p, p2;
    p.first = 1; p.second = 2; p.flag = false;
    p2.first = 3; p2.second = 4;
    
    cout << p.first << " " << p2.second << " " << p.flag;
    
    
    return 0;
    
	int x=7, vector=5;
	for(size_t i = 0; i < 5; ++i){
		int x=i;
		cout << x;
		//...
	}    
	std::vector<int> v = {1, 2, 3};
	cout << endl << x << " " << vector << " " << v[0] << endl;	
}