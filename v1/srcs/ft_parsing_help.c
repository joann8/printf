/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 20:18:11 by jacher            #+#    #+#             */
/*   Updated: 2020/12/05 22:03:35 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

unsigned int	ft_width(flag_list *flags, va_list args)
{
	int				s_tmp;
	unsigned int	width;

	width = 0;
	if(flags->b_star_width == 1)
	{
		s_tmp = (int)va_arg(args, int);
		if (s_tmp < 0)
		{
			width = -s_tmp;
			flags->b_flag_minus = 1;
		}
		else if (s_tmp > 0)
			width = s_tmp;
		flags->v_width = width;
	}
	else if (flags->v_width > 0)
		width = flags->v_width;
	return (width);
}	

unsigned int	ft_length(flag_list *flags, va_list args)
{
	unsigned int	s_tmp;
	unsigned int	length;
	
	length = 0;
	if(flags->b_star_length == 1)
	{
		s_tmp = (int)va_arg(args, int);
		if (s_tmp < 0)
		{
			length = -s_tmp;
			//flags->b_flag_minus = 1;
		}
		else
			length = s_tmp;
	}
	else if (flags->v_length > 0)
		length = flags->v_length;
	return (length);
}
