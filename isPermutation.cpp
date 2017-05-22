#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <vector>

bool isPermutation(std::string input1, std::string input2)
{

	if (input1.length() != input2.length()) {
		return false;
	}

	std::vector<int> checker(256);


	for (uint32_t i = 0; i < input1.length(); i++) {
		int flag = input1[i] - 'a';
		checker[flag]++;
	}

	for (uint32_t i = 0; i < input2.length(); i++) {
		int flag = input2[i] - 'a';
		checker[flag]--;
		if (0 > checker[flag]) {
			return false;
		}
	}
	return true; 


}


int testisPermutation()
{
	std::string test1 = "ada";
	std::string test2 = "aaa";
	std::string test3 = "amabau";
	bool result = isPermutation(test1, test2);
	if (result) {
		std::cout << "true \n";
	} else {
		std::cout << "false \n";
	}
	return 0;

}