#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define NN 500005
#include "calc.h"

char str[NN] = { '0' };
int main(int argc, char* argv[]) {
	double ans;
	FILE* in,* out;
	if (argc == 1)
		printf("Not parameters\n");
	else {
		in = fopen(argv[1], "r");
		if (argc > 2) {
			out = fopen(argv[2], "w");
		}
		else out = stdout;
		fgets(str, NN, in);
		if (korrect(str)) {
			ans = calculation(str);
			if (argc > 2)
				fprintf(out, "Ответ: %.20lf", ans);
			else printf("Ответ: %.20lf", ans);
		}
		else
			if (argc > 2)
				fprintf(out, "Ошибка в выражении");
			else printf("Ошибка в выражении");
	}
	return 0;
}