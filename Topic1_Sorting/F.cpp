#include <iostream>
#include <vector>
using namespace std;


void quick_sort(vector<int>& arr, int left, int right){
    int i = left;int j = right;
    int pivot = arr[left + (right-left)/2];
    while (i<=j){
        while (arr[i] < pivot){
            i++;
        }
        while (arr[j]> pivot){
            j--;
        }
        if (i<=j){
            int cu = arr[i];
            arr[i]= arr[j];
            arr[j] = cu;
            i++;
            j--;
        }
    }
    if (left<j){
        quick_sort(arr, left, j);
    }
    if (right>i){
        quick_sort(arr, i, right);
    }
}

int main() {
    int length;
    cin >> length;
    vector<int> arr(length);
    for (int i=0; i < length; i++){
        cin >> arr[i];
    }
    if (length > 0){
        quick_sort(arr, 0, length - 1);
    }
    for (int i=0; i < length; i++){
        cout << arr[i]<<" ";
    }
    cout<< endl;
    

    return 0;
}