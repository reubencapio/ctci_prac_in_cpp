#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <vector>


void printCharVector(std::vector<char> input1)
{
	for (char letter : input1) {
		std::cout << letter;
	}
	std::cout << "\n";

}

void replaceSpace(std::vector<char> input1)
{
	int size = input1.size();
	int blanks = 0;
	for (char test:input1) {
		if (' ' == test) {
			blanks++;
		}
	}

	int resized = size + (blanks * 2);
	input1.resize(resized);

	int index_from_end = resized - 1;
	for (int i = size - 1; i >= 0; i--) {
		if (' ' == input1[i]) {
			input1[index_from_end] = '0';
			input1[index_from_end - 1] = '2';
			input1[index_from_end - 2] = '%';
			index_from_end -= 3;

		} else {
			input1[index_from_end] = input1[i];
			index_from_end--;
		}
	}

	printCharVector(input1);
}



int testreplaceSpace()
{
	std::vector<char> test = { 'r','e',' ','b','e',' '};
	replaceSpace(test);
	return 0;
}