#include <iostream>
#include <vector>
#include <string>      
#include <sstream>     

int main() {
    std::vector<int> numbers;
    std::string line;  

    std::getline(std::cin, line);

    std::stringstream ss(line);
    int num;

    while (ss >> num) {
        numbers.push_back(num);
    }
    int lenum = numbers.size();

	int key;
	int j;
	for (int i = 1; i<lenum; i++){
		key = numbers[i];
		j = i;
		while(j >= 1 and numbers[j-1]> key){
			numbers[j] = numbers[j-1];
			j--;
		}
		numbers[j] =key;
			
	};
	
	    
	for (int i=0; i<lenum; i++){
    	std::cout << numbers[i] << " ";
	};
	std::cout << std::endl; 

	return 0;
};