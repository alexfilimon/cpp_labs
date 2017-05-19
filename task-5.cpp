//Создать динамическую структуру, которая представляет собой хеш таблицу, 
//значения которой могут принимать структуру Rect с double width, height.


//удалить все динамические структуры


#include <iostream>
using namespace std;

/*struct rect { //rectangle structure
    double width;
    double height;
};*/


struct list {   //list structure
 int value;
 list *next;   //next item's adress
};



//function with list
list* createList (const int initValue){
    list *p = new list; //allocate memory for the first item
    p->next = NULL;
    p->value = initValue;
    
    return p;
};
void addItemToList (list* &pointerOnList, const int insertionValue){
    list *p = new list;
    p->next = pointerOnList;
    p->value = insertionValue;
    
    pointerOnList = p;
};
void showList (list* &pointerOnList){
    list* p = pointerOnList;
    while (p != NULL)
    {
        cout << p->value << ' '; 
        p = p->next;                    
    }
    cout << endl;
};
list* search(list * &pointerOnList, const int searchValue){
    list* p = pointerOnList;                                                          
    while (p != NULL)
    {
        if (searchValue == p->value) {
            return p;
        }                                         
        p = p->next;
    }
    return NULL;
};

//void deleteList (list* &);


int main() {
    
    list *myList = createList(5);
    addItemToList(myList,10);
    addItemToList(myList,15);
    
    showList(myList);
    
    list *point = search(myList, 11);
    
    
    return 0;
}