#include <stdio.h>
#include "../printf.h"

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
	
	printf("\n\n1.pf | %7u\n", u);	
	ft_printf("1.my | %7u\n", u);
	printf("\n\n1.pf | %7d\n", 29);	
	ft_printf("1.my | %7d\n", 29);
	
	printf("\n\n1.pf | %.03s\n", NULL);	
	ft_printf("1.my | %.03s\n", NULL);
	printf("\n\n1.pf | %.3s\n", NULL);	
	ft_printf("1.my | %.3s\n", NULL);
	printf("\n\n1.pf | %.*s\n", -2, NULL);	
	ft_printf("1.my | %.*s\n", -1, NULL);
	
	
//TEST INT DETAILLE
/*	
	printf("\n\n1.pf | %.*d\n", -3, 1234);	
	ft_printf("1.my | %.*d", -1, 1234);
	
	
	
	printf("\n\n1.pf | %d | %d.\n", d1, d2);	
	ft_printf("1.my | %d | %d.", d1, d2);
		
	printf("\n\n2.pf | %05d | %02d.\n", d1, d1);	
	ft_printf("2.my | %05d | %02d.", d1, d1);
	printf("\n\n2.pf | %05d | %02d.\n", d2, d2);	
	ft_printf("2.my | %05d | %02d.", d2, d2);
	
	printf("\n\n3.pf | %-05d | %-02d.\n", d1, d1);	
	ft_printf("3.my | %-05d | %-02d.", d1, d1);
	printf("\n\n3.pf | %-05d | %-02d.\n", d2, d2);	
	ft_printf("3.my | %-05d | %-02d.", d2, d2);*/
		
/*	printf("\n\n4.pf | %-5d | %-2d.\n", d1, d1);	
	ft_printf("4.my | %-5d | %-2d.", d1, d1);
	printf("\n\n4.pf | %-5d | %-2d.\n", d2, d2);	
	ft_printf("4.my | %-5d | %-2d.", d2, d2);
	
	printf("\n\n5.pf | %05.7d | %02.7d.\n", d1, d1);	
	ft_printf("5.my | %05.7d | %02.7d.", d1, d1);
	printf("\n\n5.pf | %05.1d | %02.1d.\n", d1, d1);	
	ft_printf("5.my | %05.1d | %02.1d.", d1, d1);
	printf("\n\n5.pf | %05.7d | %02.7d.\n", d2, d2);	
	ft_printf("5.my | %05.7d | %02.7d.", d2, d2);
	printf("\n\n5.pf | %05.1d | %02.1d.\n", d2, d2);	
	ft_printf("5.my | %05.1d | %02.1d.", d2, d2);
	
	printf("\n\n6.pf | %5.7d | %2.7d.\n", d1, d1);	
	ft_printf("6.my | %5.7d | %2.7d.", d1, d1);
	printf("\n\n6.pf | %5.1d | %2.1d.\n", d1, d1);	
	ft_printf("6.my | %5.1d | %2.1d.", d1, d1);
	printf("\n\n6.pf | %5.7d | %2.7d.\n", d2, d2);	
	ft_printf("6.my | %5.7d | %2.7d.", d2, d2);
	printf("\n\n6.pf | %5.1d | %2.1d.\n", d2, d2);	
	ft_printf("6.my | %5.1d | %2.1d.", d2, d2);
	
	printf("\n\n7.pf | %.7d | %.2d.\n", d1, d1);	
	ft_printf("7.my | %.7d | %.2d.", d1, d1);
	printf("\n\n7.pf | %-.7d | %-.2d.\n", d1, d1);	
	ft_printf("7.my | %-.7d | %-.2d.", d1, d1);
	printf("\n\n7.pf | %.7d | %.2d.\n", d2, d2);	
	ft_printf("7.my | %.7d | %.2d.", d2, d2);
	printf("\n\n7.pf | %-.7d | %-.2d.\n", d2, d2);	
	ft_printf("7.my | %-.7d | %-.2d.", d2, d2);
	
	printf("\n\n8.pf | %8.6d | %6.8d.\n", d1, d1);	
	ft_printf("8.my | %8.6d | %6.8d.", d1, d1);
	printf("\n\n8.pf | %8.6d | %6.8d.\n", d2, d2);	
	ft_printf("8.my | %8.6d | %6.8d.", d2, d2);

*/
//TEST STRING DETAILLEE
	printf("\n\n1.pf | %s.\n",s2);	
	ft_printf("1.my | %s.", s2);
	
	printf("\n\n2.pf | %.3s | %.8s.\n", s2, s2);	
	ft_printf("2.my | %.3s | %.8s.", s2, s2);
	
	printf("\n\n3.pf | %3s | %8s.\n", s2, s2);	
	ft_printf("3.my | %3s | %8s.", s2, s2);
	
	printf("\n\n4.pf | %3.8s | %7.8s.\n", s2, s2);	
	ft_printf("4.my | %3.8s | %7.8s.", s2, s2);

	printf("\n\n5.pf | %3.8s | %10.8s.\n", s2, s2);	
	ft_printf("5.my | %3.8s | %10.8s.", s2, s2);

	printf("\n\n6.pf | %2.3s | %7.3s.\n", s2, s2);	
	ft_printf("6.my | %2.3s | %7.3s.", s2, s2);
	
	printf("\n\n7.pf | %4.3s | %7.3s.\n", s2, s2);	
	ft_printf("7.my | %4.3s | %7.3s.", s2, s2);
	
/*



	printf("\n\npf | %7.3s|%7.5s\n", s2, s3);	
	ft_printf("my | %7.3s|%7.5s", s2, s3);

	printf("\n\npf | %7.7s|%7.3s\n", s2, s3);	
	ft_printf("my | %7.7s|%7.3s", s2, s3);	

	printf("\n\npf | %7.7s|%7.7s\n", s2, s3);	
	ft_printf("my | %7.7s|%7.7s", s2, s3);

	printf("\n\npf | %3.3s|%7.7s\n", s2, s3);	
	ft_printf("my | %3.3s|%7.7s", s2, s3);	

	printf("\n\npf | %3.3s|%3.7s\n", s2, s3);	
	ft_printf("my | %3.3s|%3.7s", s2, s3);	

	printf("\n\npf | %7.7s|%3.3s\n", s2, s3);	
	ft_printf("my | %7.7s|%3.3s", s2, s3);	
	
*/
	return(0);
}
