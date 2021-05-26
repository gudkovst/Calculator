typedef struct spisok_char {
	char token;
	struct spisok_char* next;
}list_char;
typedef struct spisok_double {
	double data;
	struct spisok_double* next;
}list_double;
typedef struct Stack_token {
	list_char* top;
}stack_token;
typedef struct Stack_calc {
	list_double* top;
}stack_calc;
stack_token* create_t();
stack_calc* create_c();
void decreate_t(stack_token* s);
void decreate_c(stack_calc* s);
void push_t(stack_token* s, char t);
void push_c(stack_calc* s, double d);
char pop_t(stack_token* s);
double pop_c(stack_calc* s);
char top_t(stack_token* s);
double top_c(stack_calc* s);
int proverka_t(stack_token* s);
int proverka_c(stack_calc * s);
#pragma once
