/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:36:09 by jacher            #+#    #+#             */
/*   Updated: 2020/12/05 22:18:19 by jacher           ###   ########.fr       */
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

void	print_flags(flag_list flags)
{
	printf("flag zero = %d\n", flags.b_flag_zero); 
	printf("flag minus = %d\n", flags.b_flag_minus);
	printf("flag star width = %d\n", flags.b_star_width);
	printf("value witdh = %u\n", flags.v_width);
	printf("flag precision = %d\n", flags.b_precision);
	printf("flag star length = %d\n", flags.b_star_length);
	printf("value length = %u\n", flags.v_length);
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

int		is_a_type(char c)
{
	if (c == 'd' || c == 'c' || c == 'p' || c == 's' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

void 	flag_init(flag_list *flags)
{
	flags->b_flag_zero = 0;
	flags->b_flag_minus = 0;
	flags->v_width = 0;
	flags->b_precision = 0;
	flags->v_length = 0;
	flags->b_star_width = 0;
	flags->b_star_length = 0;
}	

int	flag_parsing(flag_list *flags, char *str, unsigned int *pos)
{
	unsigned int i;

	i = 0;
	//printf("1.str[%d] = %c\n", i, str[i]);
	if (str[i] == '-')
	{
		flags->b_flag_minus = 1;
		i++;
		if (str[i] == '0')
			i++;
	}	
	//printf("2.str[%d] = %c\n", i, str[i]);
	if (str[i] == '0')
	{
		if (str[i + 1] == '-')
		{
			flags->b_flag_minus = 1;
			i++;
		}
		else
			flags->b_flag_zero = 1;
		i++;
	}
	//printf("3.str[%d] = %c\n", i, str[i]);
	if (str[i] == '*')
	{
		flags->b_star_width = 1;
		i++;
	}	
	//printf("4.str[%d] = %c\n", i, str[i]);
	if (str[i] >= '0' && str[i] <= '9')
		flags->v_width = ft_atoi_printf(str + i, &i);
	//printf("5.str[%d] = %c\n", i, str[i]);
	if (str[i] == '.')
	{
		flags->b_precision = 1;
		i++;
	}
	if (str[i] == '*')
	{
		flags->b_star_length = 1;
		i++;
	}	
	//printf("6.str[%d] = %c\n", i, str[i]);
	if (str[i] >= '0' && str[i] <= '9')
		flags->v_length = ft_atoi_printf(str + i, &i);
	//printf("7.str[%d] = %c\n", i, str[i]);
	if (is_a_type(str[i]) == 0)
		return (0);
	*pos = *pos + i + 1;
	//printf("pos = %u | i = %u | pos + i + 1 = %u\n", *pos - i - 1, i, *pos);
	return (1);
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
	unsigned int 	plus;
	arg_list		*list;
	char 			*res;
	char 			*tmp1;
	char 			*tmp2;
	flag_list		flags;


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
		plus = 0;
		flag_init(&flags);
		while (str[i] != '%' && str[i])
			i++;
		//printf("i avant parsing = %u\n", i);
		if (str[i])
			if (flag_parsing(&flags, str + i + 1, &plus) == 0)
				return (-1);
	//	print_flags(flags);
		//printf("i apres parsing = %u\n", i);
		tmp1 = ft_strdup_pf(str, j, i);
		tmp2 = ft_strjoin_printf(res, tmp1);
		free(res);
		res = ft_strdup(tmp2);
		//printf("res = %s\n", res);
		if (res == NULL)
		{
			ft_free(res, list, str);
			va_end(args);
			return(-1);
		}
		free(tmp1);
		free(tmp2);
		j = 0;
		//printf("str[%d + %d] = %c\n", i, plus, str[i + plus]);
		while (list[j].c_init)
		{
			if (str[i + plus] == list[j].c_init)
			{		
				list[j].f(args, &res, &flags);
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
		//printf("res = %s\n", res);
		if (str[i])
			i = i + plus + 1;
	}
	va_end(args);
	ft_putstr_fd(res, 1);
	ft_free(res, list, str);
//	free_struct(list);
	return(1);
}

