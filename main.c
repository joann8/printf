#include <stdio.h>

int main()
{
	unsigned int u;
	void *ptr;

	
	u = 15;
	ptr=&u;

	printf("u=%x\n", u);	
	printf("p=%p\n", ptr);
	
	return(0);
}
