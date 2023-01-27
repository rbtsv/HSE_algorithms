#include <iostream>
#include <algorithm>

//using namespace std;

int main (){
    //freopen("t1", "r", stdin);
    int n, max1;
    std::cin >> n >> max1;
    for(int i = 1; i < n; ++i){ // ++i == i += 1 == (i = i + 1)
       int c;
       std::cin >> c;
       max1 = std::max(c, max1); 
    }   
    std::cout << max1 << "\n"; //std::endl;
    // c не видна 
    return 0;
}