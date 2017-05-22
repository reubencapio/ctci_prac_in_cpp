#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <vector>
#include <map>
#include <queue>


void fizzBuzz(int limit)
{
	for (int i = 0; i <= limit; i++) {
		if (i % 5 == 0 && i % 3 == 0) {
			std::cout << "i == " << i << "  fizzbuzz \n";
		} else if (i % 3 == 0) {
			std::cout << "i == " << i << "  fizz \n";
		} else if (i % 5 == 0) {
			std::cout << "i == " << i << "  buzz \n";
		}
	}
}

int testFizzBuzz() 
{
	fizzBuzz(100);
	return 0;
}