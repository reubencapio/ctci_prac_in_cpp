#include <iostream>
#include <string>
#include <vector>

bool isPermutation(std::string word1, std::string word2)
{
	std::vector<int> asciimap(65536);

	if (word1.length() != word2.length()){
		return false;
	}

	for (auto letter : word1)
	{
		int index = (int)letter;
		asciimap[index]++;
	}

	for (auto letter : word2)
	{
		int index = (int)letter;
		if (--asciimap[index] < 0){
			return false;
		}
	}
	return true;
}


int main()
{
	std::string word1 = "reuben";
	std::string word2 = "rubeen";
	//false == 0;  true == 1
	bool result = isPermutation(word1, word2);
	std::cout << "result == " << result << "\n";
}
