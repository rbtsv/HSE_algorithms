#include<iostream>
#include<stdexcept>

using std::cout, std::endl;

class Stack{
	int size;
    int head;
    // int stack_content[size]
    int * stack_content;
    
    class Overflow{};
    class Underflow{};
    
public:
    void push(int x);
    int pop();
    bool is_empty();
    Stack(){ //constructor
        size = 10; head = 0; stack_content = new int[size];
    }
    Stack(int s);
    ~Stack(){//destructor
        delete[] stack_content;
    }
    
    Stack(const Stack & other){ // Stack b = a; // Stack(Stack other)
    			cout << "Copy Constructor\n";			
    			size = other.size;
    			stack_content = new int[size];
    			head = other.head;
    			for(size_t i = 0; i < this->size; ++i){ // this->size <=> (*this).size <=> size
    				if( i < head)				
    					this->stack_content[i] = other.stack_content[i]; 
    				else
    					this->stack_content[i] = -1; 
    			}
    }
		
    void operator = (const Stack & other){ // *this	
    			// https://ru.wikipedia.org/wiki/Правило_трёх_(C%2B%2B)
    			cout << "operator =\n";
    			// Guard self assignment
    		    if (this == &other) // s = s;
    		        return;
			
    			delete[] stack_content;
			
    			size = other.size;
    			stack_content = new int[size];
    			head = other.head;
    			for(size_t i = 0; i < head; ++i){
    				this->stack_content[i] = other.stack_content[i];
    				// this->stack_content == // (*this).stack_content == 
    			}
			
    		}
    
	void tst_print(){
		for(size_t i = 0; i < size; ++i){
			cout << stack_content[i] << " ";
		}
		cout << endl;
	}
    
};

Stack::Stack(int s){
	size = s; head = 0; stack_content = new int[size];
}	

void Stack::push(int x){
    if( head < size ){stack_content[head++] = x;} // head++ <=> ++head, head-1
    else{ throw std::length_error("Stack overflow!111"); }
    //else{ throw Overflow(); }
}

int Stack::pop(){
    if(head > 0){ return stack_content[--head]; } // --head <=> (head -= 1)
    else{ throw Underflow(); }
}

bool Stack::is_empty(){
    return (head == 0); // do not write !head  and i[a] instead a[i]
}


int main (int argc, char const *argv[]){
	Stack s1, s2(20);
	for(size_t i = 0; i < 11; ++i){
		try{s1.push(i);}
		catch(std::length_error){ cout << "Stack Overflow!111" << endl; }
		s2.push(i);
	}
	
	s2.tst_print();
	   
    //return 0;    
	if(!s1.is_empty()){
		Stack s3 = s2, s4;
		cout << "s3:";
		s3.tst_print();
		s1.pop();	
        //cout << "Error!" << endl;
		s4 = s1;
		cout << "s4:";
		s4.tst_print();
	}    
	cout << "s1:";
	s1.tst_print();
	cout << "s2:";
	s2.tst_print();
	
		
	return 0;
}