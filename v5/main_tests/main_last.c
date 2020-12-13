#include <stdio.h>
#include "../pf.h"

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
	int a;
	int b;

	printf("pf | this %d number\n", 0);
	ft_printf("ff | this %d number\n", 0);
	
	printf("\n**** %%*.d*****\n");
	a = printf("pf %*d.\n", -6, -3);
	b = ft_printf("ff %*d.\n", -6, -3);
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %*d.\n", -3, 25);
	b = ft_printf("ff %*d.\n", -3, 25);
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %*d.\n", -1, 25);
	b = ft_printf("ff %*d.\n", -1, 25);
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %*d.\n", 0, 25);
	b = ft_printf("ff %*d.\n", 0, 25);
	printf("a = %d | b = %d\n", a , b);
	
	printf("\n**** %%-*.0d*****\n");
	a = printf("pf %-*.0d.\n", -6, -3);
	b = ft_printf("ff %-*.0d.\n", -6, -3);
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %-*.0d.\n", -3, 25);
	b = ft_printf("ff %-*.0d.\n", -3, 25);
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %-*.0d.\n", -1, 25);
	b = ft_printf("ff %-*.0d.\n", -1, 25);
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %-*.0d.\n", 0, 25);
	b = ft_printf("ff %-*.0d.\n", 0, 25);
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %0.0d.\n", 0);
	b = ft_printf("ff %0.0d.\n", 0);
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %-*.0d.\n", 0, 25);
	b = ft_printf("ff %-*.0d.\n", 0, 25);
	printf("a = %d | b = %d\n", a , b);
	

	
	printf("\n**** %%-0.0d*****\n");
	a = printf("pf %-.0d.\n", 25);
	b = ft_printf("ff %-.0d.\n", 25);
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %-.0d.\n", -25);
	b = ft_printf("ff %-.0d.\n",-25);
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %-*.*d.\n",0, 0, 25);
	b = ft_printf("ff %-*.*d.\n",0, 0, 25);
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %0*.0d.\n", 0, 25);
	b = ft_printf("ff %0*.0d.\n", 0, 25);
	printf("a = %d | b = %d\n", a , b);
	
	printf("\n****%%.*s*****\n");
	a = printf("pf %.*s.\n", -3, "hello you");
	b = ft_printf("ff %.*s.\n", -3, "hello you");
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %.*s.\n", 0, "hello you");
	b = ft_printf("ff %.*s.\n", 0, "hello you");
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %.*s.\n", 1, "hello you");
	b = ft_printf("ff %.*s.\n", 1, "hello you");
	printf("a = %d | b = %d\n", a , b);
	
	printf("\n****%%-.*s*****\n");
	a = printf("pf %-.*s.\n", -3, "hello you");
	b = ft_printf("ff %-.*s.\n", -3, "hello you");
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %-.*s.\n", 4, "hello you");
	b = ft_printf("ff %-.*s.\n", 4, "hello you");
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %-.*s.\n", 0, "hello you");
	b = ft_printf("ff %-.*s.\n", 0, "hello you");
	printf("a = %d | b = %d\n", a , b);
	
	printf("\n****%%-.0s*****\n");
	a = printf("pf %-.0s.\n","hello you");
	b = ft_printf("ff %-.0s.\n", "hello you");
	printf("a = %d | b = %d\n", a , b);
	a = printf("pf %-.s.\n", "hello you");
	b = ft_printf("ff %-.s.\n","hello you");
	printf("a = %d | b = %d\n", a , b);
	
	return(0);
}
