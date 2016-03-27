#include <iostream>
#include <string>

bool isAllUnique(std::string word)
{
	int checker = 0;

	for (int letter:word)
	{
		letter -= 'a';
		if ( (checker & (1 << letter)) > 0 ){
			return false;
		}
		checker = checker | (1 << letter);
	}
	return true;
}


int main()
{
	std::string test = "ee";
	//false == 0;  true == 1
	bool result = isAllUnique(test);
	std::cout << "result == " << result << "\n";
}
