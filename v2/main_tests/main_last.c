#include <stdio.h>
#include "printf.h"

int main()
{
	unsigned int	u;
	int				d1;
	int				d2;
	char 			*s1;
	char 			*s2;
	char 			*s3;
	char			c1;
	char 			c2;
	char 			c3;
	void			*ptr;
	void			*ptr2;

	c3 = '\0';
	u = 29;
	s1 = "abcde";
	ptr = &u;
	s2 = "hello";
	s3="world";
	c1 = 'd';
	c2 = 'j';
	ptr2 = &c1;
	d1 = -12;
	d2 = -3456;

	printf("\n\npf | %5.*d.\n", -20, 59);
	ft_printf("my | %5.*d.", -20, 59);
	
	printf("\n\npf | %.*d.\n", -20, 59);
	ft_printf("my | %.*d.", -20, 59);
	printf("\n\npf | %*.*d.\n", 35, -20, 59);
	ft_printf("my | %*.*d.", 35, -20, 59);
	printf("\n\npf | %-.3s.\n","hello");
	ft_printf("my | %-.3s.", "hello");
	printf("\n\npf | %.*s.\n", -3, "hello");
	ft_printf("my | %.*s.", -3, "hello");
	printf("\n\npf | %-*.*s.\n", -7, -3, "yolo");
	ft_printf("my | %-*.*s.", -7, -3, "yolo");
	printf("\n\npf | %.*i.\n", -6, -3);
	ft_printf("my | %.*i.", -6, -3);
	printf("\n\npf | %% *.5i 42 == |%*.5i.|\n", 4, 42);
	ft_printf("my | %% *.5i 42 == |%*.5i.|", 4, 42);

	return(0);
}
