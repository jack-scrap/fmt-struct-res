#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum {
	WD,
	HT
};

const char sep = 'x';

void err(char* msg) {
	printf("Error: %s\n", msg);
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		err("No arguments");

		return 1;
	}

	if (argc != 1 + 1 + 1) {
		err("Wrong number of arguments");

		return 1;
	}

	int res[2];

	char* strWd = argv[1];
	for (int i = 0; i < strlen(strWd); i++) {
		if (!isdigit(strWd[i])) {
			err("Character not an integer");

			return 1;
		}
	}

	res[WD] = atoi(strWd);

	char* strHt = argv[2];
	for (int i = 0; i < strlen(strHt); i++) {
		if (!isdigit(strHt[i])) {
			err("Character not an integer");

			return 1;
		}
	}

	res[HT] = atoi(strHt);

	printf("%d%c%d\n", res[WD], sep, res[HT]);

	return 0;
}
