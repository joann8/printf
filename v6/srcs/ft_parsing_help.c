/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 20:18:11 by jacher            #+#    #+#             */
/*   Updated: 2020/12/12 21:15:09 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

void	ft_star(t_flag *flags, va_list args)
{
	int				s_tmp;

	if (flags->b_star_width == 1)
	{
		if ((s_tmp = (int)va_arg(args, int)) < 0)
		{
			flags->v_width = -s_tmp;
			flags->b_flag_minus = 1;
			flags->b_flag_zero = 0;
		}
		else
			flags->v_width = s_tmp;
	}
	if (flags->b_star_length == 1)
	{
		if ((s_tmp = (int)va_arg(args, int)) < 0)
		{
			flags->b_precision = 0;
			flags->v_length = 0;
		}
		else
			flags->v_length = s_tmp;
	}
}

void	flag_parsing_width(t_flag *flags, char *str, unsigned int *index)
{
	unsigned int i;

	i = *index;
	flags->b_width = 1;
	if (str[i] == '*')
	{
		flags->b_star_width = 1;
		i++;
	}
	else if (str[i] == '-' && str[i + 1] == '*')
	{
		flags->b_star_width = 1;
		flags->b_flag_minus = 1;
		flags->b_flag_zero = 0;
		i++;
	}
	else
		flags->v_width = ft_atoi_printf(str + i, &i, flags, 1);
	*index = i;
}

void	flag_parsing_precision(t_flag *flags, char *str, unsigned int *index)
{
	unsigned int i;

	i = *index;
	flags->b_precision = 1;
	i++;
	if (str[i] == '*')
	{
		flags->b_star_length = 1;
		i++;
	}
	else if (str[i] == '-')
	{
		flags->b_precision = 0;
		flags->v_length = 0;
		i++;
	}
	else
		flags->v_length = ft_atoi_printf(str + i, &i, flags, 2);
	*index = i;
}

int		flag_parsing(t_flag *flags, char *str, unsigned int *pos,
						va_list args)
{
	unsigned int i;

	i = 0;
	if (str[i] == '-')
	{
		flags->b_flag_minus = 1;
		i++;
	}
	if (str[i] == '0' && i == 0)
	{
		flags->b_flag_zero = 1;
		i++;
	}
	if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '*')
		flag_parsing_width(flags, str, &i);
	if (str[i] == '.')
		flag_parsing_precision(flags, str, &i);
	if (is_a_type(str[i]) == 0)
		return (0);
	*pos = *pos + i + 1;
	ft_star(flags, args);
	if (flags->b_precision == 1 && (str[i] == 'x' || str[i] == 'X' ||
			str[i] == 'i' || str[i] == 'u' || str[i] == 'd'))
		flags->b_flag_zero = 0;
	return (1);
}
