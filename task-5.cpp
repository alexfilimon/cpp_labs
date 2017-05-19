//Создать динамическую структуру, которая представляет собой хеш таблицу, 
//значения которой могут принимать структуру Rect с double width, height.


//удалить все динамические структуры


#include <iostream>
//#include <cmath>
using namespace std;

const int size = 10;

struct rect { //rectangle structure
    double width;
    double height;
};


struct list {   //list structure
 rect value;
 list *next;   //next item's adress
};


rect inputRect(){
    rect cur;
    
    cout << "Input width of rectangle, please: ";
    cin >> cur.width;
    cout << "Input height of rectangle, please: ";
    cin >> cur.height;
    
    return cur;
};
void showRect(rect curRect){
    cout << curRect.width << " " << curRect.height << "\t";
};
bool equalRects(rect rect1, rect rect2){
    if (rect1.width == rect2.width && rect1.height == rect2.height) return true;
    return false;
};


//function with list
list* createList (rect initValue){
    list *p = new list; //allocate memory for the first item
    p->next = NULL;
    p->value = initValue;
    
    return p;
};
void addItemToList (list* &pointerOnList, rect insertionValue){
    list *p = new list;
    p->next = pointerOnList;
    p->value = insertionValue;
    
    pointerOnList = p;
};
void showList (list* &pointerOnList){
    list* p = pointerOnList;
    while (p != NULL)
    {
        showRect(p->value); 
        p = p->next;                    
    }
    cout << endl;
};
list* search(list * &pointerOnList, rect searchValue){
    list* p = pointerOnList;                                                          
    while (p != NULL)
    {
        if (equalRects(searchValue, p->value)) {
            return p;
        }                                         
        p = p->next;
    }
    return NULL;
};
void deleteList (list* &pointerOnList, list* &pointerOnDeletedItem){
    list *p = pointerOnList;
    if (pointerOnDeletedItem == NULL) {
        cout << "Number you want to delete doesn't exist" << endl;
        return;
    }
    if (p != 0){
        if (pointerOnList == pointerOnDeletedItem) {
            list *cur = pointerOnList;
            pointerOnList = cur->next;
            delete cur;
        } else {
            while (p->next != pointerOnDeletedItem){
                p = p->next;
            }
            list *temp = p->next;
            p->next = (p->next)->next;
            delete temp;
        }
    
        
    }
};


//function for hash
int getHashKeyFromRect(rect cur_rect){
    int key;
    
    key = ((int)(cur_rect.height + cur_rect.width)) % size;
    
    return key;
};
void showHashTable(list  &hashTable){
    /*for (int i=0;i<size;i++){
        if (hashTable[i] == NULL) cout << 0 << endl;
        //else showList(*hashTable[i]);
        else cout << endl << *(hashTable+i) << endl;
    }*/
};




int main() {
    list *hashTable[size];
    for (int i=0;i<size;i++) {
        hashTable[i] = NULL;
    }
    
    
    rect rect1 = inputRect();
    //cout << rect1.width << " " << rect1.height << " " << getHashKeyFromRect(rect1);
    
    int hash = getHashKeyFromRect(rect1);
    
    cout << "Hash: " << hash << endl;
    
    hashTable[hash] = createList(rect1);
    
    //showHashTable(*&hashTable);
    
    showList(hashTable[2]);
    
    
    
    /*list *myList = createList(5);
    addItemToList(myList, 11);
    addItemToList(myList, 15);
    addItemToList(myList, 20);
    addItemToList(myList, 25);
    
    showList(myList);
    
    list *p = search(myList, 20);
    deleteList(myList, p);
    
    showList(myList);*/
    
    
    return 0;
}