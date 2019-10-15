//
//  A Stack is an abstract data type that serves as a collection
// of elements, with two principal operations are push & pop
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/data-scructures/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Afzal Rao
// Github: @thecasuist
//
#include <iostream>
using namespace std;

struct node{ //Defn of an element of stack as a struct
    int data;
    node *link;
};

class stack{ 
    node *top;
    public:
    int pop(); //Removes the topmost element 
    void push(int x); //Pushes the element onto the top of the stack
    void display();
    stack(){ //Constructor to initialise the stack
        top = NULL;
    }
};

int stack::pop(){
    if(top==NULL){
        cout << "STACK UNDERFLOW\n";
        return -1;
    }
    else{
        int ans = top->data;
        node *temp = top;
        top = top->link;
        delete temp;
        return ans;
    }
}

void stack::push(int x){
    node *temp = new node;
    if(temp){
        temp->data = x;
        temp->link = top;
        top = temp;
        cout << "Element successfully pushed\n";
    }
    else{
        cout << "STACK OVERFLOW\n";
    }    
}

void stack::display(){
    node *temp = top;
    while(temp!= NULL){
        cout << temp->data << " ";
        temp = temp->link;
    }
}

int main(){
    cout << "Stack has been initialised... \n";
	stack s; int c;
	while(1){
		cout << "\nEnter 1 to push an element\nEnter 2 to pop an element\nEnter 3 to display all the content of stack\nEnter 0 to exit\n";
		cin >> c;
		switch(c){
			case 0: return 0;
			case 1:
			{
				cout << "Enter element to be pushed\n";
				int x;
				cin >> x;
				s.push(x);
				break;
			}
			case 2:
			{
				printf("Poped Element Is %d\n",s.pop());
				break;
			}
			case 3:
			{
				printf("Stack has the following content in order LIFO\n");
				s.display();
				break;
			}
			default:
			{
				printf("Wrong Choice\n");
			}
		}
	}
    return 0;
}
