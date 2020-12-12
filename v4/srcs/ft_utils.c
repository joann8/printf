/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:36:09 by jacher            #+#    #+#             */
/*   Updated: 2020/12/10 15:55:26 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

int			look_for_function(char c, va_list args, int *res, t_flag *flags)
{
	int bol;

	bol = 0;
	if (c == 's')
		bol = ft_string(args, res, flags);
	else if (c == 'd')
		bol = ft_int(args, res, flags);
	else if (c == 'i')
		bol = ft_int(args, res, flags);
	else if (c == 'c')
		bol = ft_char(args, res, flags);
	else if (c == '%')
		bol = ft_percent(args, res, flags);
	else if (c == 'u')
		bol = ft_unsint(args, res, flags);
	else if (c == 'x')
		bol = ft_x(args, res, flags);
	else if (c == 'X')
		bol = ft_bigx(args, res, flags);
	else if (c == 'p')
		bol = ft_p(args, res, flags);
	return (bol);
}

int			is_a_type(char c)
{
	if (c == 'd' || c == 'c' || c == 'p' || c == 's' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

void		flag_init(t_flag *flags)
{
	flags->b_flag_zero = 0;
	flags->b_flag_minus = 0;
	flags->b_width = 0;
	flags->v_width = 0;
	flags->b_precision = 0;
	flags->v_length = 0;
	flags->b_star_width = 0;
	flags->b_star_length = 0;
}
