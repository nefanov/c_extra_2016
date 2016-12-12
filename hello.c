#include "hello.h"

void hello(const char *fname)
{
	char a[128];
	FILE *f = fopen(fname,"r");
	while(fscanf(f, "%s",a))
		printf("%s", a);
	return;
}
