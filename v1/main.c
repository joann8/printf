#include <stdio.h>
#include "printf.h"

int main()
{
	unsigned int	u;
	char 			*s1;
	char 			*s2;
	char			c1;
	char c2;
	
	u = 29;
	s1 = "deux";
	s2 = "quatre\n";
	c1 = 'd';
	c2 = 'j';

	printf("\n\n%%%d.pf | un %-*s %5c trois %-4s %-*c cinq%%\n",1, -20, s1,c1, s2, -5, c2);	
	ft_printf("\n%%%d.my | un %-*s %5c trois %-4s %-*c cinq%%\n",1, -20, s1,c1, s2, -5, c2);	


/*
 // TEST 
	printf("\n***original %%***\nabc%%efghi%% \n\n");	

	printf("\npf | abc%%cefghi%%c\n");	
	ft_printf("my | abc%%cefghi%%c");	

// TEST STRING
	printf("\n***original string***\nun %%s trois %%s cinq avec s1=deux et s2=quatre\n\n");	

	printf("\n\npf | un %s trois %s cinq\n", s1, s2);	
	ft_printf("my | un %s trois %s cinq", s1, s2);	
	printf("\n\npf | un %10s trois %4s cinq\n", s1, s2);	
	ft_printf("my | un %10s trois %4s cinq", s1, s2);	
	printf("\n\npf | un %-10s trois %-4s cinq\n", s1, s2);	
	ft_printf("my | un %-10s trois %-4s cinq", s1, s2);	
	printf("\n\npf | un %.10s trois %.4s cinq\n", s1, s2);	
	ft_printf("my | un %.10s trois %.4s cinq", s1, s2);
	printf("\n\npf | un %-.10s trois %-.4s cinq\n", s1, s2);	
	ft_printf("my | un %-.10s trois %-.4s cinq", s1, s2);
	printf("\n\npf | un %-10.5s trois %-10.4s cinq\n", s1, s2);	
	ft_printf("my | un %-10.5s trois %-10.4s cinq", s1, s2);	
	//printf("\n\npf | un %-010.5s trois %-010.4s cinq\n", s1, s2);	
	//ft_printf("my | un %s trois %s cinq", s1, s2);	
	//printf("\n\npf | un %s trois %s cinq\n", s1, s2);	
	//ft_printf("my | un %s trois %s cinq", s1, s2);	
	printf("\n\npf | un %-*s trois %*s cinq\n", 5, s1, 6, s2);	
	ft_printf("my | un %-*s trois %*s cinq", 5, s1, 6, s2);	
	printf("\n\npf | un %-*s trois %-4s cinq\n", -20, s1, s2);	
	ft_printf("my | un %-*s trois %-4s cinq", -20, s1, s2);	

 // TEST CHAR
	printf("\n\n***original char***\nabc%%efghi%% avec c1=d et c2=j\n");	

	printf("\npf | abc%cefghi%c\n", c1, c2);	
	ft_printf("my | abc%cefghi%c", c1, c2);	
	printf("\n\npf | abc%-10cefghi%c\n", c1, c2);	
	ft_printf("my | abc%-10cefghi%c", c1, c2);	
	//printf("pf | abc%05cefghi%cj\n", c1, c2);	
	//ft_printf("my | abc%05cefghi%cj\n\n", c1, c2);	
	//printf("pf | abc%.5cefghi%cj\n", c1, c2);	
	//ft_printf("my | abc%.5cefghi%cj\n\n", c1, c2);	
	printf("\n\npf | abc%5cefghi%c\n", c1, c2);	
	ft_printf("my | abc%5cefghi%c", c1, c2);
	printf("\n\npf | abc%*cefghi%*c\n", 2, c1, 'a', c2);	
	ft_printf("my | abc%*cefghi%*c", 2, c1, 'a', c2);	
	printf("\n\npf | abc%*cefghi%c\n", -2, c1, c2);	
	ft_printf("my | abc%*cefghi%c", -2, c1, c2);	
	printf("\npf | abc%-*cefghi%c\n", -2, c1, c2);	
	ft_printf("my | abc%-*cefghi%c", -2, c1, c2);	
*/
	/*printf("pf u=%-10d--->fin\n", u);	
	ft_printf("my u=%-10d--->fin\n", u);	
	
	printf("pf u=%10d--->fin\n", u);	
	ft_printf("my u=%10d--->fin\n", u);	
	printf("pf u=%010d--->fin\n", u);	
	ft_printf("my u=%010d--->fin\n", u);	
	printf("pf s=%-10s--->fin\n", s);	
	ft_printf("my s=%-10s--->fin\n", s);	
	printf("pf s=%10s--->fin\n", s);	
	ft_printf("my s=%10s--->fin\n", s);	
	printf("pf s=%4s--->fin\n", s);	
	ft_printf("my s=%4s--->fin\n", s);	*/

	return(0);
}
