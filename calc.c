#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

#include "stack.h"


int korrect(char str[500000]) {
	int N = strlen(str);
	int q = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == '(') q++;
		if (str[i] == ')') q--;
		if (q < 0) return 0;
		if (i > 1 && !type(str[i]) && !type(str[i - 1])) return 0;
		if (type(str[i]) == 3) return 0;
	}
	if (q) return 0;
	return 1;
}

int prioritet(char x) {
	if (x == '(') return 1;
	if (x == ')') return 2;
	if (x == '+' || x == '-') return 3;
	return 4;
}
int type(char x) {
	if (x == '*' || x == '/' || x == '+' || x == '-') return 0;
	if (x >= '0' && x <= '9') return 1;
	if (x == '(' || x == ')') return 2;
	return 3;
}
double operat(char op, double a2, double a1) {
	if (op == '+') return a1 + a2;
	else if (op == '-') return a1 - a2;
	else if (op == '*') return a1 * a2;
	else if (op == '/') return a1 / a2;
}

double calculation(char str[500000]) {
	stack_token* s_t = create_t();
	stack_calc* s_c = create_c();
	stack_calc* sign = create_c();
	int t = 0, N = strlen(str);
	double sost = 0, ans;
	for (int i = 0; i < N; i++) {
		char c = str[i];
		if (c == ' ') continue;
		if (c == '0' && !t) {
			push_c(s_c, 0);
			sost = 1;
			continue;
		}
		if (sost == 0 && c == '-' && !t) {
			sost = -1;
			continue;
		}
		else if (!sost) sost = 1;
		if (type(c) == 1)
			t = t * 10 + (c - '0');
		else {
			if (t) {
				double td = 1;
				td *= (t * sost);
				push_c(s_c, td);
				t = 0;
				sost = 1;
			}
			int f = prioritet(c);
			if (f == 1) {
				push_c(sign, sost);
				push_t(s_t, c);
				sost = 0;
			}
			else if (f == 2) {
				double s;
				while (top_t(s_t) != '(') {
					double a2 = pop_c(s_c), a1 = pop_c(s_c);
					push_c(s_c, operat(pop_t(s_t), a2, a1));
				}
				pop_t(s_t);
				if (!proverka_c(sign)) s = pop_c(sign);
				else s = 1;
				push_c(s_c, pop_c(s_c) * s);
			}
			else {
				while (!proverka_t(s_t) && prioritet(top_t(s_t)) >= f) {
					double a2 = pop_c(s_c), a1 = pop_c(s_c);
					push_c(s_c, operat(pop_t(s_t), a2, a1));
				}
				push_t(s_t, c);
			}

		}
	}
	if (t) {
		double td = 1;
		td *= (t * sost);
		push_c(s_c, td);
	}
	while (!proverka_t(s_t)) {
		double a2 = pop_c(s_c), a1 = pop_c(s_c);
		push_c(s_c, operat(pop_t(s_t), a2, a1));
	}
	ans = pop_c(s_c);
	decreate_t(s_t);
	decreate_c(s_c);
	decreate_c(sign);
	return ans;
}