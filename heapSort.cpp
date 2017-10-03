//heap sort

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

void siftDown(int *arr, int n, int cur) {
    int largest = cur; 
    int left = 2*cur + 1;
    int right = 2*cur + 2;
    
    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    
    if (largest != cur) {
        swap(arr[largest], arr[cur]);
        
        siftDown(arr, n, largest);
    }
}

void heapSort(int *arr, int n) {
    //start timer
    unsigned int timeStart = clock(); // timer start
    
    for (int i = n/2 - 1; i >= 0; i--) {
        siftDown(arr, n, i);
    }
    
    for (int i = n-1; i>=0; i--) {
        swap(arr[i], arr[0]);
        
        siftDown(arr, i, 0);
    }
    
    //end timer
    cout << endl << "-----Remaining time: " << ( (double)(clock()-timeStart)/(double)CLOCKS_PER_SEC ) << "sec ------" << endl << endl;
}

bool test(int *arr, int n){
    for (int i = 0; i < n-1; i++) {
        if (arr[i+1] < arr[i]) {
            return false;
        }
    }
    return true;
}

int prepareArray(int *& arr, int &n, char inputType) {
    if (inputType == 'f') {
        ifstream in("input.txt");
        in >> n;
        
        arr = new int[n];
        
        int i = 0;
        while(!in.eof() && i < n) {
            in >> arr[i++];
        }
        if(in.eof() && i < n) {
            cout << endl << "There is not enough data in the file..." << endl;
            return 1;
        }
    } else if (inputType == 'r') {
        cout << "Input 'n': " << endl;
        cin >> n;
        
        arr = new int[n];
        
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10000 - 5000;
        }
    }
    
    return 0;
}


int main() {
    
    
    
    //settings
    bool showMass; // do user want to show the mass
    char inputType; // status of inputing
    int status; // status of error
    
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
    
    //creating the mass
    int *arr;
    int n; // size of array
    
    //preparing
    status = prepareArray(arr, n, inputType);
    if (status) return status;
    
    //setup random
    srand(time(0));
    
    
    
   
    
    
    cout << endl << "--------------------------------"<< endl;
    cout << "Heap sorting";
    cout << endl << "--------------------------------"<< endl;
    
    //showing
    if (showMass) {
        cout << "Unsorted array: " << endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    //sorting
    heapSort(arr, n);
    
    //showing
    if (showMass) {
        cout << "Sorted array: " << endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    //testing
    bool testVosr = test(arr, n);
    if (testVosr) {
        cout << endl << "Test successfully done";
    } else {
        cout << endl << "Unsuccessful test !!!";
    }
    cout << endl;
    
    delete[] arr;
    
    return 0;
}
