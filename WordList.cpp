// WordList.cpp: определяет точку входа для консольного приложения.
//
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
#include<ctype.h>
typedef struct List {
	int cnt;
	char *word;
	struct List * next;
} List;

/*
List *list_add1(List *head, char *s) {
	List *a, *b;
	a = (List*)malloc(sizeof(List));
	(a->word) = s;
	a->next = NULL;
	if (head == NULL) {
		return a;
	}
	head->next = a;
	return a;
}*/
/*
int main() {
	List *a, *b, *f;
	char *c;
	int sum = 0;
	int i=1,j=0,k=0;
	FILE * fp,*fo;
	a = NULL;
	b = NULL;
	fp = fopen("input.txt", "r");
	//fo = fopen("output.txt", "w");
	c = (char*)malloc(40 * sizeof(char));
	fscanf(fp, "%s ", c);
	a = list_add1(a, c);
	a->cnt = 0;
	b = a;
	c = (char*)malloc(10 * sizeof(char));
	while (fscanf(fp, "%s ", c) != -1) {
		if (isupper((b->word)[0])) {
			a = list_add1(a, c);
			a->cnt = 0;
			c = (char*)malloc(40 * sizeof(char));
		}
		else {
			printf("%s",)
		}       
	}
	a = b;
	while (a != NULL) {
		printf("%s ",a->word);
		a = a->next;
	}
	//a = b;
	 while (a != NULL) {
		b = a;
		if (isupper((b->word)[0])) {
			while (b != NULL) {
				if (strcmp(a->word, b->word) == 0) {
					if (j > 0) {
						if (b->cnt == 0) {
							b->cnt = i;
							k++;
						}
					}
				}
				j++;
				b = b->next;
			}
		}
		if (k > 0) {
			i++;
		}
		j = 0;
		k = 0;
		a = a->next;
	} */
	//a = f;
	//while (a != NULL) {
			//printf("%s ",a->word);
		//a = a->next;
	//}
	//a = f;
/*	while (a != NULL) {
		b = a->next;
		free(a->word);
		free(a);
		a = b;
	}
	fclose(fp);
	fclose(fp);
	return 0;
}
*/
int k = 0;

void ListAdd(List **head, char * data) {
	List *tmp = (List*)malloc(sizeof(List));
	tmp->word = (char*)malloc(40 * sizeof(char));
	memmove(tmp->word, data, 40 * sizeof(char));
	///tmp->pword = data;
	k++;
	tmp->cnt = k;
	tmp->next = (*head);
	(*head) = tmp;
}

List * FindSame(List  * head, char * uWord) {
	if (head == NULL) {
		return NULL;
	}
	List *dp = FindSame(head->next, uWord);
	if (strcmp((head->word), uWord) == 0) {
		return head;
	}
	return dp;
}

int main() {
	List *a = NULL, *b;
	FILE * fp;
	char *c;
	fp = fopen("input.txt", "r");
	c = (char*)malloc(40 * sizeof(char));
	while (fscanf(fp, "%s ", c) != -1) {
		if (isupper(c[0])) {
			b = FindSame(a, c);
			if (b) {
				printf("[%d] ", b->cnt);
			}
			else {
				ListAdd(&a, c);
				printf("%s ", c);
			}
		}
		else
		{
			printf("%s ", c);
		}
	}
	return 0;
}