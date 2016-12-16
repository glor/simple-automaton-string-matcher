#include<stdio.h>
#include"matcher.h"

int main(void) {
	char str[100];
	matcher_t* m = make_matcher();
	while(1) {
		int modus=getchar();
		if(modus==EOF)
			return 0;
		int i=0;
		int c;
		while((c=getchar())!='\n' && c!=EOF) {
			str[i++] = c;
		}
		str[i] = 0;
		switch(modus) {
			case '?':
				printf("%d\n", match(m,str));
				break;
			case '+':
				add_word(m,str, 1);
				break;
			case '-':
				remove_word(m,str);
				break;
			default:
				fprintf(stderr,"error: wrong input\n");
				return 1;
		}
	}
	return 0;
}

