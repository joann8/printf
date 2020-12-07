/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:36:09 by jacher            #+#    #+#             */
/*   Updated: 2020/12/07 16:50:34 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"



int	str_analysis(char **str, int *res, va_list args, arg_list *list)
{
	unsigned int		 i;
	unsigned int		 j;
	unsigned int		 plus;
	char 				*tmp1;
	//char 				*tmp2;
	flag_list			flags;

	(void)res;
	i = 0;
	while ((*str)[i] != '\0')
	{
		j = i;
		plus = 0;
		flag_init(&flags);
		while ((*str)[i] != '%' && (*str)[i])
			i++;
		if ((*str)[i])
			if (flag_parsing(&flags, *str + i + 1, &plus, args) == 0)
				return (-1);
		tmp1 = ft_strdup_pf(*str, j, i);
		ft_putstr(tmp1);
		*res += ft_strlen(tmp1);
		free(tmp1);
	/*	if (*res == NULL)
		{
			ft_free(*res, list, *str);
			va_end(args);
			return(-1);
		}*/
		j = 0;
		while (list[j].c_init)
		{
			if ((*str)[i + plus] == list[j].c_init)
			{		
				if (((list[j].f(args, res, &flags)) == -1))
				{
					ft_free(list, *str);
					va_end(args);
					return(-1);
				}
				break;
			}
			j++;
		}
		if ((*str)[i])
			i = i + plus + 1;
	}
	return (1);
}

int ft_printf(const char *input, ...)
{
	va_list			args;
	char 			*str;
	arg_list		*list;
	int				res;

	res = 0;
	list = struct_init();
	str = ft_strdup(input);
	va_start(args, input);
	
	if ((str_analysis(&str, &res, args, list) == -1))
		return (-1);

	va_end(args);
	ft_free(list, str);
//	free_struct(list);
	return(res);
}
