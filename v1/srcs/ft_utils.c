/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:36:09 by jacher            #+#    #+#             */
/*   Updated: 2020/12/06 17:43:37 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void ft_free(char *res, arg_list *list, char *str)
{
	if (res)
		free(res);
	if (str)
		free(str);
	if (list)
		free(list);
}

arg_list	*struct_init(void)
{
	arg_list 	*list;

	if (!(list = malloc(sizeof(arg_list) * 10)))
		return(NULL);
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
	return (list);
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
