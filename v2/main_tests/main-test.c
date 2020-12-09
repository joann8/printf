/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:36:09 by jacher            #+#    #+#             */
/*   Updated: 2020/12/03 15:04:38 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int main(int ac, char **av)
{
	(void)ac;
	int d;
	char c;
	unsigned int u;
	unsigned int x; 
	char *str1;
	char *str2;
	char *str3;
	void *ptr;

	
	d = -20;
	u = 99;
	c = 'u';
	x = 1024;
	str1 = "Jolene";
	str2 = "old";
	str3 = "trois";
	ptr = &x;

	printf("\n**** My printf ****\n");
	ft_printf(av[1], str1, c, d, str2);
	
	printf("\n\n**** My printf ****\n");
	ft_printf(av[2], str1, str1, str1);
	
	printf("\n\n**** My printf ****\n");
	ft_printf(av[3], u, d, d);
	
	printf("\n\n**** My printf ****\n");
	ft_printf(av[4], x, x, x);
	
	printf("\n\n**** Add ****\n");
	printf("printf add=%p\n", ptr);
	ft_printf("my printf add=%p", ptr);
	
	/*printf("\n**** Normal printf - good values ****\n");
	printf(av[1], str1, c, d, str2);
	printf("\n**** Normal printf - bad values ****\n");
	printf(av[1], str1, c, str2);
	printf("\n**** Normal printf - good values ****\n");
	printf("hello %s, how are %c? I am %d year %s", str1, c, d, str2); */
	/*printf("\n**** Normal printf - bad values ****\n");
	printf("hello %s, how are %c? I am %d year %s",str1, c, d); */
	
	//ft_printf(av[1], av[2], av[3], av[4],av[5]);
	return (0);
}
