#include <iostream>
#include <string>
#include <vector>

std::string compressString(std::string word)
{
	int length = word.length();
	int repCtr = 1;
	std::string compressed;
	for (int i = 0; i < length; i++){
		char letter = word[i];
		if (letter == word[i + 1]){
			repCtr++;
		} else{
			if (repCtr > 1){
				compressed += letter + std::to_string(repCtr);
				repCtr = 1;
			}else {
				compressed += letter + std::to_string(1);
				repCtr = 1;
			}
		}
	}
	if (compressed.length() < word.length()){
		return compressed;
	}else{
		return word;
	}
}



int main()
{
	std::string word = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
	std::string output = compressString(word);
	std::string word2 = "reub";
	std::string output2 = compressString(word2);
	std::string word3 = "r";
	std::string output3 = compressString(word3);
}
