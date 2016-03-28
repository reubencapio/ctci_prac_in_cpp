#include <stdio.h>

void reverse(char* str)
{
	char* first = str;
	char* last = str;
	char temp;
	if (*str) {
		while (*last) {
			last++;
		}
		last--;

		while (first < last) {
			temp = *last;
			*last-- = *first;
			*first++ = temp;
		}
	}

	while (*str) {
		printf("%c", *str);
		str++;
	}
}

int main()
{
	char test[] = "reuben";
	reverse(test);
}
