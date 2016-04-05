#include <iostream>
#include <string>

bool isRotation(std::string word1, std::string word2)
{
	bool result = false;
	if (word1.length() == word2.length() && word1.length() > 0){
		std::string wordRotated = word1 + word1;
		result = wordRotated.find(word2) != std::string::npos;
	}
	return result;
}


int main()
{
	std::string word1 = "reddit";
	std::string word2 = "ditred";
	bool result = isRotation(word1, word2);
	std::cout << result << "\n";
}
