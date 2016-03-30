#include <iostream>
#include <string>
#include <vector>

void replaceSpaces(char* word, int length)
{
	char *pword = word;
	int spaceCtr = 0;
	int newLength = 0;

	for (int i = 0; i < length; i ++){
		if (*pword++ == ' '){
			spaceCtr++;
		}
	}
	pword--;
	newLength = length + (spaceCtr * 2);
	word[newLength] = '\0';
	for (int i = length; i >= 0; i--){
		if (' ' == *pword){
			word[newLength - 1] = '0';
			word[newLength - 2] = '2';
			word[newLength - 3] = '%';
			newLength -= 3;
		}else{
			word[newLength - 1] = *pword;
			newLength--;
		}	
		pword--;
	}
}



int main()
{
	char word[13] = " reuben ";
	for (int i = 0; i < 13; i++){
		std::cout << word[i];
	}
	std::cout << "\n";
    replaceSpaces(word, 8);
	for (int i = 0; i < 13; i++){
		std::cout << word[i];
	}
	std::cout << "\n";

}
