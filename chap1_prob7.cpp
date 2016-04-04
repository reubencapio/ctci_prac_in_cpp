#include <iostream>
#include <string>
#include <vector>
#include <random>
//#include <algorithm>
#include <functional>

void setToZero(std::vector<std::vector<int>> &an_array)
{
	std::vector<int> row((int)an_array.size());
	std::vector<int> column((int)an_array[0].size());

	for (int i = 0; i < (int)an_array.size(); i++){
		for (int j = 0; j < (int)an_array[0].size(); j++){
			if (an_array[i][j] == 0){
				row[i] = 1;
				column[j] = 1;
			}
		}
	}

	for (int i = 0; i < (int)an_array.size(); i++){
		for (int j = 0; j < (int)an_array[0].size(); j++){
			if (1 == row[i] || 1 == column[j]){
				an_array[i][j] = 0;
			}
		}
	}
	
}


int numDigits(int number)
{
	if (0 == number){
		return 1;
	}
	int digits = 0;
	while (number) {
		number /= 10;
		digits++;
	}
	return digits;
}



int main()
{
	std::vector<std::vector<int>> testArray = {
		{ 1, 2, 0, 4, 33 },
		{ 5, 6, 7, 8, 44 },
		{ 9, 10, 11, 12, 0 },
		{ 13, 14, 15, 16, 66 },
		{ 9, 18, 19, 20, 0 }
	};

	std::cout << "before setting to zeros: " << "\n";
	for (int i = 0; i < (int)testArray.size(); i++){
		for (int j = 0; j < (int)testArray[0].size(); j++){
			if (numDigits(testArray[i][j]) == 1){
				std::cout << "  " << testArray[i][j];
			}
			else{
				std::cout << " " << testArray[i][j];
			}
		}
		std::cout << "\n";
	}

	setToZero(testArray);


	std::cout << "after setting to zeros: " << "\n";
	for (int i = 0; i < (int)testArray.size(); i++){
		for (int j = 0; j < (int)testArray[0].size(); j++){
			if (numDigits(testArray[i][j]) == 1){
				std::cout << "  " << testArray[i][j];
			}
			else{
				std::cout << " " << testArray[i][j];
			}
		}
		std::cout << "\n";
	}
}
