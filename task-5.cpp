//Создать динамическую структуру, которая представляет собой хеш таблицу, 
//значения которой могут принимать структуру Rect с double width, height.


//удалить все динамические структуры


#include <iostream>
#include <cmath>
#include <fstream>
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

int inputNumOfOperation();


bool isDouble(string str){
    bool znak = false;
    int len = str.length();
    if (str[0] > '0' && str[0] <'9') {
        for (int i=1;i<len;i++) {
            char cur = str[i];
            if (cur == '.' || cur == ',') {
                if (znak) {
                    return false;
                } else {
                    znak = true;
                }
            } else if (cur < '0' || cur > '9') {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
};
double parseDoubleFromStr(string str) {
    int len = str.length();
    double num = 0;
    bool wasZnak = false;
    int count = 0;
    for (int i=0;i<len;i++) {
        char cur = str[i];
        if (wasZnak) {
            count++;
            num = num*10 + (cur - '0');
        } else {
            if (cur == '.' || cur == ',') {
                wasZnak = true;
            } else {
                num = num*10 + (cur - '0');
            }
        }
    };
    
    return (num / pow(10,count));
};
double inputDouble(string text){
    cout << text;
    string str;
    cin >> str;
    //cout << str << " " << isDouble(str) << endl;
    if (isDouble(str)) {
        double cur = parseDoubleFromStr(str);
        
        return cur;
    } else {
        cout << "Вы ввели некорректное значение..." << endl;
        return inputDouble(text);
    }
};

//functions for rect
rect inputRect(){
    rect cur;
    ifstream in ("rects.txt"); //Открываем файл для считывания информации 
    
    /*string text = "Введите ширину прямоугольника: ";
    cur.width = inputDouble(text);
    text = "Введите высоту прямоугольника: ";
    cur.height = inputDouble(text);*/
    
    return cur;
};
void showRect(rect curRect){
    cout << "{" << curRect.width << ", " << curRect.height << "} ";
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
void showHashTable(list * *hashTable){
    for (int i=0;i<size;i++){
        cout << "Hash[" << i << "]: ";
        if (hashTable[i] == NULL) {
            cout << "--no data--" << endl;
        }
        else {
            showList(hashTable[i]);
        }
        //else cout << endl << *(hashTable+i) << endl;
    }
};


//other functions
bool isStrInt(string str){
    int len = str.length();
    for (int i=0;i<len;i++) {
        char cur = str[i];
        if (cur < '0' || cur > '9') return false;
    }
    return true;
};
int parseIntFromStr(string str){
    int len = str.length();
    int num = 0;
    for (int i=0;i<len;i++) {
        char cur = str[i];
        num = num*10 + (cur - '0');
    }
    return num;
};
int inputNumOfOperation(){
    cout << "Команды:\n"
		 << "\t 1. Печать списка\n"
		 << "\t 2. Добавить новый элемент\n"
		 << "\t 3. Удалить элемент\n"
		 << "\t 0. Выход\n";
    cout << "Введите код операции: ";
    string str;
    //getline(cin, str);
    cin >> str;
    if (isStrInt(str)) {
        int num = parseIntFromStr(str);
        //cout << num;
        if (num < 0 || num > 4){
            cout << "Вы ввели неправильный код операции..." << endl;;
            return inputNumOfOperation();
        }
        return num;
    } else {
        cout << "Вы ввели не число..." << endl;
        return inputNumOfOperation();
    }
    
    
};

void addRectToHashTable(list **table) {
    rect curRect = inputRect();
    int hash = getHashKeyFromRect(curRect);
    if (table[hash] == NULL) {
        list *curList = createList(curRect);
        table[hash] = curList;
    } else {
        addItemToList(table[hash], curRect);
    }
};

void deleteRectFromHashTable(list **hashTable){
    rect curRect = inputRect();
    
    
    list *listCur = search(hashTable[getHashKeyFromRect(curRect)],curRect);
    //cout << listCur << endl;
    
    deleteList(hashTable[getHashKeyFromRect(curRect)], listCur);
};



int main() {
    list *hashTable[size];
    for (int i=0;i<size;i++) {
        hashTable[i] = NULL;
    }
    
    enum comands {EXIT, PRINT, ADD, DELETE};
	
	int oper = inputNumOfOperation();
    comands operation = (comands) oper;
    //cout << "Operation: " << operation << ", Int:" << oper << endl;
    
    while (operation) {
        switch(operation) {
            case EXIT: return 0; break;
            case PRINT: showHashTable(hashTable); break;
            case ADD: addRectToHashTable(hashTable); break;
            case DELETE: deleteRectFromHashTable(hashTable); break;
        }
        
        oper = inputNumOfOperation();
        operation = (comands) oper;
    }
    
    
    
    
    return 0;
}