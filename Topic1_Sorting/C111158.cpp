#include  <iostream>
#include <vector>
#include <string>
#include <sstream>

int main(){
    std::vector<int> numbers;
    std::string line;

    std::getline(std::cin, line);

    std::stringstream ss(line);
    int num;

    while (ss >> num){
        numbers.push_back(num);
    };

    int lenum = numbers.size();

    int curi;
    for (int i = 0; i < lenum-1; i++){
        curi = i;
        for (int j = i+1; j< lenum;j++){
            if (numbers[i] < numbers[j]){
                int cu = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = cu;
            };
        };
    };

    for (int i=0; i<lenum;i++){
        std::cout << numbers[i] << " ";
    };
    std::cout<< std::endl;

    return 0;
};