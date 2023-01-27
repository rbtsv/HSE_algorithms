#include <iostream>
#include <algorithm>

using namespace std;

int main (){
    freopen("tm2", "r", stdin);
    //std::ios::sync_with_stdio(false); std::cin.tie(0);
    int n, a, b;    
    std::cin >> n >> a >> b;
    
    int64_t m1, m2;
    m1 = max(a,b);
    m2 = min(a,b);
    
    for(int i = 2; i < n; ++i){ 
        int c;
        cin >> c;
        if( c > m1 ){
            m2 = m1;
            m1 = c;            
        }else{ m2 = max(m2, (int64_t) c); }
    }   
    std::cout << m1 * m2 << "\n"; //std::endl;    
    return 0;
}