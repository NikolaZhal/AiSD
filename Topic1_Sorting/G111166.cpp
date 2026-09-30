#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void CountSort(std::vector<int>& A) {
    int count[101] = {0};
    int lenum = A.size();
    
    for (int i = 0; i < lenum; i++) {
        count[A[i]]++;
    }
    
    int index = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j < count[i]; j++) {
            A[index] = i;
            index++;
        }
    }
}

int main() {
    std::vector<int> numbers;
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int num;
    
    while (ss >> num) {
        numbers.push_back(num);
    }
    
    CountSort(numbers);
    
    int lenum = numbers.size();
    for (int i = 0; i < lenum; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}