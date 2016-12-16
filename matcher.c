#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"matcher.h"

matcher_t* make_matcher() {
	matcher_t* n = malloc(sizeof(matcher_t));
	n->id = 0;
	n->use = 0;
	for(int i=0; i<255; i++) {
		n->next[i] = NULL;
	}
	return n;
}

void destroy_matcher(matcher_t* m) {
	free(m);
}

void add_word(matcher_t* n, char* str, int id) {
	int i = 0;
	while(str[i]) {
		if(n->next[str[i]]==NULL) {
			n->next[str[i]] = make_matcher();
		}
		n = n->next[str[i]];
		n->use++;
		i++;
	}
	n->id = id;
}

int remove_word(matcher_t* m, char* str) {
	if(*str==0)
		return 1;
	m->use--;
	if(remove_word(m->next[*str],str+1)) {
		m->next[*str] = NULL;
	}
	return (m->use==0);
}

int match(matcher_t* n, char* str) {
	int pos = 0;
	while(str[pos]) {
		if(n->next[str[pos]]==NULL) {
			return 0;
		}
		n = n->next[str[pos]];
		pos++;
	}
	return n->id;
}

