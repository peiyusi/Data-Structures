#include <iostream>
#include <algorithm>
using namespace std;

bool isHeapSort(int *init, int *arr, int n);
int getNextHeapSortIndex(int *arr, int n);
void heapSortOnce(int *arr, int index);

int main(void) {
    int n;
    cin >> n;
    int *init = new int[n];
    int *arr = new int[n];
    for(int i = 0; i < n; ++i)
        cin >> init[i];
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    if(isHeapSort(init, arr, n)) {
        cout << "Heap Sort" << endl;
        heapSortOnce(arr, getNextHeapSortIndex(arr, n));
    } else
        cout << "Insertion Sort" << endl;

    cout << arr[0];
    for(int i = 1; i < n; ++i)
        cout << " " << arr[i];

    delete[] init;
    delete[] arr;
    return 0;
}

/*
 * 1. ?????????????? -> ?????????
 * 2. ????????,?????????????,??????
*/
bool isHeapSort(int *init, int *arr, int n) {
    int len = 1;    //???????,????????
    for(int i = 0; i < n - 1; ++i) {
        if(arr[i] > arr[i + 1]) {
            len = i + 1;
            break;
        }
    }

    for(int i = len; i < n; ++i)
        if(arr[i] != init[i]) return true;

    sort(arr, arr + len + 1);   //??????,?????????????
    return false;
}

//???????????????????
int getNextHeapSortIndex(int *arr, int n) {
    int heap = arr[0];
    for(int i = 1; i < n; ++i) {
        if(arr[i] > heap) return i - 1;
    }
    return n - 1;   //???,????
}

void heapSortOnce(int *arr, int index) {
    swap(arr[0], arr[index]);
    int size = index - 1;
    //???
    int tmp = arr[0];
    int parent = 0;
    int child;
    for(; parent*2 + 1 <= size; parent = child) {
        child = parent * 2 + 1;
        if(child < size && arr[child] < arr[child + 1]) ++child;

        if(tmp > arr[child]) break;
        else arr[parent] = arr[child];
    }
    arr[parent] = tmp;
}

