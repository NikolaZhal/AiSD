#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> merge(const vector<int>&, const vector<int>&);

vector<int> merge_sort(vector<int> arr){
    int size = arr.size();
    if (size<=1){
        return arr;
    }
    int mid = size /2;
    vector<int> lefthalf(arr.begin(), arr.begin()+ mid);
    vector<int> righthalf(arr.begin()+mid, arr.end());
    vector<int> left = merge_sort(lefthalf);
    vector<int> right = merge_sort(righthalf);

    return merge(left, right);
}

vector<int> merge(const vector<int>& left, const vector<int>& right){
    int i = 0, j = 0;
    int sizel =  left.size();
    int sizer =  right.size();
    vector<int> answer;
    while (i < sizel && j < sizer){
        if (left[i] > right[j]){
            answer.push_back(right[j]);
            j++;
        } else {
            answer.push_back(left[i]);
            i++;
        }
    }
    if ( i<  sizel){

        answer.insert(answer.end(), left.begin()+i, left.end());
        
    }
    if (j < sizer){
        answer.insert(answer.end(), right.begin()+j, right.end());
    }
    return answer;
}


int main(){
    int length;
    cin >> length;
    vector<int> arr(length);
    for (int i=0; i < length ; i++  ){

        cin >> arr[i];
    }
    vector<int> sorted = merge_sort(arr);
    for (int i = 0; i< length; i++){
        cout << sorted[i]<<' ';
    }
    cout<< endl;

    return 0;
}
