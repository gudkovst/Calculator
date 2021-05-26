#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

#include "stack.h"

stack_token* create_t() {
	stack_token* s = (stack_token*)malloc(sizeof(stack_token));
	s->top = NULL;
	return s;
}
stack_calc* create_c() {
	stack_calc* s = (stack_calc*)malloc(sizeof(stack_calc));
	s->top = NULL;
	return s;
}
void decreate_t(stack_token* s) {
	while (s->top) {
		list_char* t = s->top;
		s->top = t->next;
		free(t);
	}
}
void decreate_c(stack_calc* s) {
	while (s->top) {
		list_double* t = s->top;
		s->top = t->next;
		free(t);
	}
}
void push_t(stack_token* s, char t) {
	list_char* p = (list_char*)malloc(sizeof(list_char));
	p->token = t;
	p->next = s->top;
	s->top = p;
}
void push_c(stack_calc* s, double d) {
	list_double* p = (list_double*)malloc(sizeof(list_double));
	p->data = d;
	p->next = s->top;
	s->top = p;
}
char pop_t(stack_token* s) {
	list_char* p = s->top;
	char r = p->token;
	s->top = p->next;
	free(p);
	return r;
}
double pop_c(stack_calc* s) {
	list_double* p = s->top;
	double r = p->data;
	s->top = p->next;
	free(p);
	return r;
}
char top_t(stack_token* s) {
	return s->top->token;
}
double top_c(stack_calc* s) {
	return s->top->data;
}
int proverka_t(stack_token* s) {
	return (s->top == NULL);
}
int proverka_c(stack_calc* s) {
	return (s->top == NULL);
}