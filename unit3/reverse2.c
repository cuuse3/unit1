
#include <stdio.h>
#include <string.h>

int main(void) {
	char s[1024];

	// read a token (number) from stdin
	if (scanf("%1023s", s) != 1) {
		return 0;
	}

	int neg = 0;
	char *p = s;
	int len = (int)strlen(s);

	// handle optional leading sign
	if (s[0] == '-') {
		neg = 1;
		p = s + 1;
		len -= 1;
	}

	// reverse the digits in-place using pointers
	char *start = p;
	char *end = p + len - 1;
	while (start < end) {
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}

	// print sign if any, then reversed digits
	if (neg) putchar('-');
	printf("%s\n", p);

	return 0;
}
