/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 20:18:11 by jacher            #+#    #+#             */
/*   Updated: 2020/12/09 15:15:41 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_width(flag_list *flags, va_list args)
{
	int				s_tmp;
	unsigned int	width;

	width = 0;
	s_tmp = (int)va_arg(args, int);
	if (s_tmp < 0)
	{
		width = -s_tmp;
		flags->b_flag_minus = 1;
	}
	else if (s_tmp > 0)
		width = s_tmp;
	flags->v_width = width;
	return ;
}

void	ft_length(flag_list *flags, va_list args)
{
	int				s_tmp;
	unsigned int	length;

	length = 0;
	s_tmp = (int)va_arg(args, int);
	if (s_tmp < 0)
	{
		flags->b_precision = 0;
		flags->v_length = 0;
		if (flags->b_width == 0)
			flags->b_flag_minus = 1;
	}
	else
		length = s_tmp;
	flags->v_length = length;
	return ;
}

void	flag_parsing_width(flag_list *flags, char *str, unsigned int *index)
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
		i++;
	}
	else
		flags->v_width = ft_atoi_printf(str + i, &i, flags);
	*index = i;
}

void	flag_parsing_precision(flag_list *flags, char *str, unsigned int *index)
{
	unsigned int i;

	i = *index;
	flags->b_precision = 1;
	flags->b_flag_zero = 0;
	i++;
	if (str[i] == '*')
	{
		flags->b_star_length = 1;
		i++;
	}
	else if (str[i] == '-' && str[i + 1] == '*')
	{
		flags->b_star_length = 1;
		i++;
	}
	else
		flags->v_length = ft_atoi_printf(str + i, &i, flags);
	*index = i;
}

int		flag_parsing(flag_list *flags, char *str, unsigned int *pos,
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
	if (flags->b_star_width == 1)
		ft_width(flags, args);
	if (flags->b_star_length == 1)
		ft_length(flags, args);
	return (1);
}
