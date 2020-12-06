/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/06 12:13:20 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include <stdio.h>

void	ft_x(va_list args, char **res, flag_list *flags)
{
	unsigned int	d;
	char			*tmp;
	char			*tmp1;
	char			*tmp2;
	unsigned int	width;
	unsigned int	length;
	
	width = 1;
	length = 1;
	if (flags->v_width > 0 || flags->b_star_width == 1)
		width = ft_width(flags, args);
	if (flags->b_precision == 1)
		length = ft_length(flags, args);
	d = va_arg(args, unsigned int);
	tmp = ft_itoa_x(d, 'x');
	if (width < ft_strlen(tmp))
		width = ft_strlen(tmp);
	if (length < ft_strlen(tmp)) 
		length = ft_strlen(tmp);
	if (length > width)
	{	
		flags->b_flag_zero = 1;
		width = length;
	}
	if (!(tmp1 = malloc(sizeof(char) * (width + 1))))
	{
		free(*res);
		return; //erreur
	}
	if (flags->b_flag_minus == 1 && flags->v_width != 0)
		ft_int_left(tmp, tmp1, width);
	else
	{
		if (flags->b_flag_zero == 1)	
			ft_int_right(tmp, tmp1, width, '0');
		else
			ft_int_right(tmp, tmp1, width, ' ');
	}
	//ft_putnbr_fd(d, 1);
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
}

void	ft_X(va_list args, char **res, flag_list *flags)
{
	unsigned int	d;
	char			*tmp;
	char			*tmp1;
	char			*tmp2;
	unsigned int	width;
	unsigned int	length;
	
	width = 1;
	length = 1;
	if (flags->v_width > 0 || flags->b_star_width == 1)
		width = ft_width(flags, args);
	if (flags->b_precision == 1)
		length = ft_length(flags, args);
	d = va_arg(args, unsigned int);
	tmp = ft_itoa_x(d, 'X');
	if (width < ft_strlen(tmp))
		width = ft_strlen(tmp);
	if (length < ft_strlen(tmp)) 
		length = ft_strlen(tmp);
	if (length > width)
	{	
		flags->b_flag_zero = 1;
		width = length;
	}
	if (!(tmp1 = malloc(sizeof(char) * (width + 1))))
	{
		free(*res);
		return; //erreur
	}
	if (flags->b_flag_minus == 1 && flags->v_width != 0)
		ft_int_left(tmp, tmp1, width);
	else
	{
		if (flags->b_flag_zero == 1)	
			ft_int_right(tmp, tmp1, width, '0');
		else
			ft_int_right(tmp, tmp1, width, ' ');
	}
	//ft_putnbr_fd(d, 1);
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
}
