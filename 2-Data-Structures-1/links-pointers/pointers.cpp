#include<iostream>

using namespace std;

void inc(int &x){ // not void( int x) because argument is a copy of the input
    x += 1;
}

void pinc(int * x){
    *x = *x + 1;
}


void print_anything(void * any){
	//int* thing = (int*) any; 
	cout << "any:" << *((int*) any) << endl;
}

void move_any_pointer(void ** one, void ** two){ // Bad approach
	*one = *two;
}


template <typename C> void p_anything(C *any){ //Good Approach
	//int* thing = (int*) any; 
	cout << "any:" << *any << endl;
}

void int_p_anything(int *any){
	//int* thing = (int*) any; 
	cout << "any:" << *any << endl;
}

int main (int argc, char const *argv[]){
	int x, y, *px, *py;	
    int &lx = x; // almost int * lx; lx = &x;
	
    
    // x = y; // means we copy content of &y to &x
    
	x = 7;
	y = -1;
    
    px = &x;
    py = &y;
    move_any_pointer((void **) &px, (void **) &py);    
    cout << *px << " " << *py << endl;
    
    return 0;
    
    px = &x;
    *px += 1; 
    lx -= 2;
    
    print_anything(px);
    p_anything(&y);
    
    return 0;
    
    cout << x;
    inc(x);
    pinc(px); // input is the copy of px
    cout << "->" << x << endl;
    
    //return 0;
    
    
    cout << x << " " << *px <<  " " << lx << endl;		
    
    cout << " ==== " << endl;
    
    px = &y;
    py = &x;
    
    cout << x << " " << *px <<  " " << y << " " << *py  << endl;
    
    cout << " ==== " << endl;
    
    const int &ly = y;
    
    //ly += 1; // Error! 
    y += 1;
    
	cout << y  << " " << ly << endl;
    
    cout << " ==== " << endl;
    
    int **ppx;		
    
    ppx = &px;
    //ppx = &py;
    
    (*ppx) += 1;   
    cout << *(*ppx) << endl;
    cout << &x << " " << &y << endl;
    
	//system("open link-pointer.jpeg");
	//system("open pointer-pointer.jpeg");
	//system("open int_star.jpeg");
	system("open void_star.jpeg"); 			
	return 0;
}