#include <iostream>
#include <string>
#include <vector>
#include <random>
//#include <algorithm>
#include <functional>

int numDigits(int number)
{
	int digits = 0;
	while (number) {
		number /= 10;
		digits++;
	}
	return digits;
}
  
void rotate2DArray(std::vector<std::vector<int>> &TwoDArray, int layers)
{
	for (int i = 0; i < layers / 2; i++){
		int last = layers - 1 - i;
		for (int j = i; j < last; j++){
			int offset = j - i;
			int temp = TwoDArray[i][j];
			TwoDArray[i][j] = TwoDArray[(last-offset)][i];
			TwoDArray[(last - offset)][i] = TwoDArray[last][last-offset];
			TwoDArray[last][last - offset] = TwoDArray[j][last];
			TwoDArray[j][last] = temp;




			for (int k = 0; k < layers; k++){
				for (int l = 0; l < layers; l++){
					if (numDigits(TwoDArray[k][l]) == 1){
						std::cout << "  " << TwoDArray[k][l];
					}
					else{
						std::cout << " " << TwoDArray[k][l];
					}
				}
				std::cout << "\n";
			}
			std::cout << "\n";
		}
	}
}





int main()
{
	std::vector<std::vector<int>> testArray = { 
												{ 1, 2, 3, 4, 33},
												{ 5, 6, 7, 8, 44},
												{ 9, 10, 11, 12, 55},
												{ 13, 14, 15, 16, 66},
												{ 17, 18, 19, 20, 77}
	                                          };
	int layers = 5;
	std::cout << "before rotate: " << "\n";
	for (int i = 0; i < layers; i++){
		for (int j = 0; j < layers; j++){
			if (numDigits(testArray[i][j]) == 1){
				std::cout << "  " << testArray[i][j];
			}else{
				std::cout << " " << testArray[i][j];
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	rotate2DArray(testArray, layers);
	std::cout << "after rotate: " << "\n";
	for (int i = 0; i < layers; i++){
		for (int j = 0; j < layers; j++){
			if (numDigits(testArray[i][j]) == 1){
				std::cout << "  " << testArray[i][j];
			}else{
				std::cout << " " << testArray[i][j];
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
