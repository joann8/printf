/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:36:09 by jacher            #+#    #+#             */
/*   Updated: 2020/12/03 14:49:24 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static int	count_arg(char *str)
{
	unsigned int i;
	unsigned int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1]) // cas ou %%?
			count++;
		i++;
	}
	return (count);
}

void	print_struct(arg_list *list)
{
	unsigned int i;

	i = 0;
	while (list[i].c_init)
	{
		printf("i = %d || struct.car = %c\n", i, list[i].c_init);
		i++;
	}
}

//not working as is
void	free_struct(arg_list *list)
{
	unsigned int i;

	i = 0;
	while (list[i].c_init)
	{
		free(&list[i].c_init);
		//free(list[i].f);
		i++;
	}
}

void	struct_init(arg_list *list)
{
	list[9].c_init = '\0';
	
	list[0].c_init = 's';
	list[0].f = &ft_string;
	list[1].c_init = 'd';
	list[1].f = &ft_int;
	list[2].c_init = 'i';
	list[2].f = &ft_int;
	list[3].c_init = 'c';
	list[3].f = &ft_char;
	list[4].c_init = '%';
	list[4].f = &ft_percent;
	list[5].c_init = 'u';
	list[5].f = &ft_unsint;
	list[6].c_init = 'x';
	list[6].f = &ft_x;
	list[7].c_init = 'X';
	list[7].f = &ft_X;
	list[8].c_init = 'p';
	list[8].f = &ft_p;

}

void ft_free(char *res, arg_list *list, char *str)
{
	if (res)
		free(res);
	if (str)
		free(str);
	if (list)
		free(list);
}

int ft_printf(const char *input, ...)
{
	va_list			args;
	char 			*str;
	unsigned int	count;
	unsigned int	i;
	unsigned int	j;
	arg_list		*list;
	char 			*res;
	char 			*tmp1;
	char 			*tmp2;
	
	res = ft_strdup("");

	list = malloc(sizeof(arg_list) * 10);
	struct_init(list);
	//print_struct(list);	
	
	str = ft_strdup(input);
	//printf("str = %s\n",str);
	
	count = count_arg(str);
	//printf("count string = %d\n", count);
	//cmt compter le nbre d'arg dans une focnton aevc different inputs?
	
	i = 0;
	va_start(args, input);
	while (str[i] != '\0')
	{
		j = i;
		while (str[i] != '%' && str[i])
			i++;
		tmp1 = ft_strdup_pf(str, j, i);
		tmp2 = ft_strjoin_printf(res, tmp1);
		free(res);
		res = ft_strdup(tmp2);
		if (res == NULL)
		{
			ft_free(res, list, str);
			va_end(args);
			return(-1);
		}
		free(tmp1);
		free(tmp2);
		j = 0;
		while (list[j].c_init)
		{
			if (str[i + 1] == list[j].c_init)
			{		
				list[j].f(args, &res);
				if (res == NULL)
				{
					ft_free(res, list, str);
					va_end(args);
					return(-1);
				}
				break;
			}
			j++;
		}
		i += 2;
	}
	va_end(args);
	ft_putstr_fd(res, 1);
	ft_free(res, list, str);
//	free_struct(list);
	return(1);
}

