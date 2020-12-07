/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/07 17:02:56 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include <stdio.h>

int		ft_x(va_list args, int *res, flag_list *flags)
{
	unsigned int	d;
	char			*tmp;
	char			*tmp1;
	unsigned int	width;
	unsigned int	length;

	d = va_arg(args, unsigned int);
	tmp = ft_itoa_x(d, 'x');
	width = ft_strlen(tmp);
	length = ft_strlen(tmp);
	if (flags->b_width == 1 && width < flags->v_width)
		width = flags->v_width;
	if (flags->b_precision == 1)
	{
		flags->b_flag_zero = 0;
		if (length < flags->v_length)
			length = flags->v_length;
		if (length > width)
		{	
			flags->b_flag_zero = 1;
			width = length;
		}
	}
	if (!(tmp1 = malloc(sizeof(char) * (width + 1))))
	{
		free(tmp);
		*res = -1;
		return (-1); //erreur
	}
	if (flags->b_flag_minus == 1)
		ft_int_left(tmp, tmp1, width);
	else
	{
		if (flags->b_flag_zero == 1)	
			ft_int_right_0(tmp, tmp1, width, length);
		else
			ft_int_right(tmp, tmp1, width);
	}
	ft_putstr(tmp1);
	*res += ft_strlen(tmp1);
	free(tmp1);
	free(tmp);
	return (1);
}

int		ft_X(va_list args, int *res, flag_list *flags)
{
	unsigned int	d;
	char			*tmp;
	char			*tmp1;
	unsigned int	width;
	unsigned int	length;

	d = va_arg(args, unsigned int);
	tmp = ft_itoa_x(d, 'X');
	width = ft_strlen(tmp);
	length = ft_strlen(tmp);
	if (flags->b_width == 1 && width < flags->v_width)
		width = flags->v_width;
	if (flags->b_precision == 1)
	{
		flags->b_flag_zero = 0;
		if (length < flags->v_length)
			length = flags->v_length;
		if (length > width)
		{	
			flags->b_flag_zero = 1;
			width = length;
		}
	}
	if (!(tmp1 = malloc(sizeof(char) * (width + 1))))
	{
		free(tmp);
		return ((*res = -1)); //erreur
	}
	if (flags->b_flag_minus == 1)
		ft_int_left(tmp, tmp1, width);
	else
	{
		if (flags->b_flag_zero == 1)	
			ft_int_right_0(tmp, tmp1, width, length);
		else
			ft_int_right(tmp, tmp1, width);
	}
	ft_putstr(tmp1);
	res += ft_strlen(tmp1);
	free(tmp1);
	free(tmp);
	return (1);
}
