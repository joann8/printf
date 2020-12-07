#include <stdio.h>
#include "printf.h"

int main()
{
	unsigned int	u;
	char 			*s1;
	char 			*s2;
	char			c1;
	char 			c2;
	void			*ptr;
	void			*ptr2;

	u = 29;
	s1 = "deux";
	ptr = &u;
	s2 = "quatre\n";
	c1 = 'd';
	c2 = 'j';
	ptr2 = &c1;

// TEST ADD
	printf("\n\npf | un %-25p deux %p trois \n", ptr, ptr2);	
	ft_printf("my | un %-25p deux %p trois \n", ptr, ptr2);	
	/*printf("\n\npf | un %0p deux %-5p trois \n", ptr, ptr2);	
	ft_printf("my | un %0p deux %-5p trois \n", ptr, ptr2);	
	printf("\n\npf | un %0p deux %05p trois \n",  ptr, ptr2);	
	ft_printf("my | un %0p deux %05p trois \n", ptr, ptr2);	
	printf("\n\npf | un %p deux %-.5p trois \n",  ptr, ptr2);	
	ft_printf("my | un %p deux %-.5p trois \n",  ptr, ptr2);	
	printf("\n\npf | un %010p deux %-.8p trois \n",  ptr, ptr2);	
	ft_printf("my | un %010p deux %-.8p trois \n", ptr, ptr2);	*/
	
// TEST HEXA
	printf("\n\npf | un %x deux %X trois %X\n", 11, 222, 333);	
	ft_printf("my | un %x deux %X trois %X\n", 11, 222, 333);	
	printf("\n\npf | un %0x deux %-5X trois %05x\n", 11, -222, 333);	
	ft_printf("my | un %0x deux %-5X trois %05x\n", 11, -222, 333);	
	printf("\n\npf | un %0x deux %05X trois %05x\n", 11, -222, 333);	
	ft_printf("my | un %0x deux %05X trois %05x\n", 11, -222, 333);	
	printf("\n\npf | un %x deux %-.5x trois %.5x\n", 11, -222, 333);	
	ft_printf("my | un %x deux %-.5x trois %.5x\n", 11, -222, 333);	
	printf("\n\npf | un %010x deux %-.8x trois %-8X.\n", 11, -222, 333);	
	ft_printf("my | un %010x deux %-.8x trois %-8X.\n", 11, -222, 333);	
	
// TEST UNSIN 
	printf("\n\npf | un %u deux %u trois %u\n", 11, 222, 333);	
	ft_printf("my | un %u deux %u trois %u\n", 11, 222, 333);	
	printf("\n\npf | un %0u deux %-5u trois %05u\n", 11, -222, 333);	
	ft_printf("my | un %0u deux %-5u trois %05u\n", 11, -222, 333);	
	printf("\n\npf | un %0u deux %05u trois %05u\n", 11, -222, 333);	
	ft_printf("my | un %0u deux %05u trois %05u\n", 11, -222, 333);	
	printf("\n\npf | un %u deux %-.5u trois %.5u\n", 11, -222, 333);	
	ft_printf("my | un %u deux %-.5u trois %.5u\n", 11, -222, 333);	
	printf("\n\npf | un %010u deux %-.8u trois %-8u.\n", 11, -222, 333);	
	ft_printf("my | un %010u deux %-.8u trois %-8u.\n", 11, -222, 333);	
	

//* TEST INT
	printf("\n\npf | un %d deux %d trois %d\n", 11, -222, 333);	
	ft_printf("my | un %d deux %d trois %d\n", 11, -222, 333);	
	printf("\n\npf | un %7i deux %07i trois %-7i %010.5i\n", -14, -14, -14, -14);	
	ft_printf("my | un %7i deux %07i trois %-7i %010.5i\n", -14, -14, -14, -14);	
	printf("\n\npf | un %0d deux %05d trois %05d\n", 11, -222, 333);	
	ft_printf("my | un %0d deux %05d trois %05d\n", 11, -222, 333);	
	printf("\n\npf | un %d deux %-.5d trois %.5d\n", 11, -222, 333);	
	ft_printf("my | un %d deux %-.5d trois %.5d\n", 11, -222, 333);	
	printf("\n\n pf | un %010d deux %-.8d trois %-8d.\n", 11, -222, 333);	
	ft_printf("my | un %010d deux %-.8d trois %-8d.\n", 11, -222, 333);	


//TEST GENERAL

	printf("\n\n%%%d.pf | un %-*s %5c trois %-4s %-*c cinq%%\n",1, -20, s1,c1, s2, -5, c2);	
	ft_printf("\n%%%d.my | un %-*s %5c trois %-4s %-*c cinq%%\n",1, -20, s1,c1, s2, -5, c2);	



 /*/ TEST 
	printf("\n***original %%***\nabc%%efghi%% \n\n");	

	printf("\npf | abc%%cefghi%%c\n");	
	ft_printf("my | abc%%cefghi%%c");	
*/
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
