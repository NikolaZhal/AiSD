#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(){

    int lenum;
    cin>>lenum;
    vector <int> numbers(lenum);
    int i, j;
    int counted =0;

    for (i=0; i < lenum; ++i){
        cin >> numbers[i];
    }
    

    bool swaped = true;
    i=0;
    while (swaped &&  i < lenum){
        swaped = false;
        for (j = 0; j<lenum - i-1; j++){
            if (numbers[j] > numbers[j+1]){
                int he = numbers[j];
                numbers[j]= numbers[j+1];
                numbers[j+1] = he;
                counted++;
                swaped = true;
            }
        }
        i++;
    }



    // for (i = 0; i < lenum; i++){
    //     cout << numbers[i] << ' ';
    // }
    cout << counted << endl;



    return 0;
}
