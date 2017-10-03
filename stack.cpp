//stack

#include <iostream>

using namespace std;

struct stack {
    stack * next;
    int data;
};

void addToStack(stack *& p, int data) {
    stack * curP = new stack;
    curP->data = data;
    curP->next = p;
    p = curP;
}

void getFromStack(stack *& p) {
    if (p != NULL) {
        stack * curP = p;
        int curData = curP->data;
        p = curP->next;
        
        delete curP;
        
        cout << "Element: " << curData << endl;
    } else {
        cout << "No elements more: ";
    }
}

stack * createStack(int data) {
    stack * curP = new stack;
    curP->next = NULL;
    curP->data = data;
}

void deleteStack(stack * p) {
    while(p->next != NULL) {
        stack * curP = p;
        p = p->next;
        delete curP;
    }
    p = NULL;
}



int main() {
    
    stack * p = createStack(5);
     
    addToStack(p, 10);
    addToStack(p, 20);
    addToStack(p, 30);
    getFromStack(p);
    getFromStack(p);
    
    getFromStack(p);
    getFromStack(p);
    getFromStack(p);
    
    deleteStack(p);
    
    
}
