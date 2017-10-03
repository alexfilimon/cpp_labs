//quick sort

#include <iostream>
#include <fstream>
#include <time.h> //timer

using namespace std;

// swap elements
void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

// quick sort
void qs(int *a, int left, int right, bool methodSortRandom) {
    int op;
    if (methodSortRandom == true) {
        op = a[rand() % (right - left) + left];
    } else {
        op = a[(left + right) / 2];
    }
    int l = left, r = right;
    while(l <= r) {
        while(op > a[l]) {
            l++;
        }
        while(op < a[r]) {
            r--;
        }
        if (l <= r){
            swap(a[l++], a[r--]);
        }
    }
    if (left < r){
        qs(a, left, r, methodSortRandom);
    }
    if (right > l){
        qs(a, l, right, methodSortRandom);
    }
}

bool test(int *a, int n){
    for (int i = 0; i < n-1; i++) {
        if (a[i+1] < a[i]) {
            return false;
        }
    }
    return true;
} 

int sort(int *a , int n, char inputType, bool showMass, bool methodSortRandom) {
    //input values
    if (inputType == 'r') {
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 10000 - 5000;
        }
    } else {//input type file('f')
        ifstream in("input.txt");
        int i = 0;
        while(!in.eof() && i < n) {
            in >> a[i++];
        }
        if(in.eof() && i < n) {
            cout << endl << "There is not enough data in the file..." << endl;
            return 1;
        }
    }
    
    //show mass before sorting
    if (showMass) {
        cout << "Unsorted array: " << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    
    //sorting
    unsigned int timeStart = clock(); // timer start
    qs(a, 0, n-1, methodSortRandom);
    
    //end timer
    cout << endl << "Remaining time: " << ( (double)(clock()-timeStart)/(double)CLOCKS_PER_SEC ) << "sec" << endl;
    
    
    //show mass after sorting
    if (showMass) {
        cout << "Sorted array: " << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    
    
    //testing
    bool testVosr = test(a, n);
    if (testVosr) {
        cout << endl << "Test successfully done";
    } else {
        cout << endl << "Unsuccessful test !!!";
    }
    cout << endl;
    
    return 0;
}

int main() {
    
    
    
    //settings
    bool showMass;
    char inputType;
    
    //show the mass
    char symbol;
    cout << "Would you like to show the mass?(y/n)" << endl;
    cin >> symbol;
    if (symbol == 'y') {
        showMass = true;
    } else {
        showMass = false;
    }
    
    //input type
    do {
        cout << "Choose the input type: \n\tr - random\n\tf - file" << endl;
        cin >> inputType;
    } while(inputType != 'r' && inputType != 'f');
    
    
    
    int n;
    cout << "Input 'n': " << endl;
    cin >> n;
    
    srand(time(0));
    
    //creating the mass
    int *a = new int[n], *b = new int[n];
    
    int status; // status of error
    
    
    cout << endl << "--------------------------------"<< endl;
    cout << "Random choosing the base element";
    cout << endl << "--------------------------------"<< endl;
    status = sort(a, n, inputType, showMass, true);
    if (status != 0) return status;
    delete[] a;
    
    
    cout << endl << "--------------------------------"<< endl;
    cout << "Manual choosing the base element";
    cout << endl << "--------------------------------"<< endl;
    status = sort(b, n, inputType, showMass, false);
    if (status != 0) return status;
    delete[] b;
    //sort(int *a , int n, char inputType, bool showMass, bool methodSortRandom)
    
    return 0;
}
