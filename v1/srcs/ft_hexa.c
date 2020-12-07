/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/07 13:38:10 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include <stdio.h>

int		ft_x(va_list args, char **res, flag_list *flags)
{
	unsigned int	d;
	char			*tmp;
	char			*tmp1;
	char			*tmp2;
	unsigned int	width;
	unsigned int	length;
	
	d = va_arg(args, unsigned int);
	tmp = ft_itoa_x(d, 'x');
	width = ft_strlen(tmp);
	length = ft_strlen(tmp);
/*	if (flags->v_width > 0 || flags->b_star_width == 1)
		width = ft_width(flags, args);
	if (flags->b_precision == 1)
		length = ft_length(flags, args);*/
	//if (width < ft_strlen(tmp))
	//	width = ft_strlen(tmp);
	//if (length < ft_strlen(tmp))
	//	length = ft_strlen(tmp);	
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
	//ft_putnbr_fd(d, 1);
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
	free(tmp1);
	free(tmp2);
	free(tmp);
	return (1);
}

int		ft_X(va_list args, char **res, flag_list *flags)
{
	unsigned int	d;
	char			*tmp;
	char			*tmp1;
	char			*tmp2;
	unsigned int	width;
	unsigned int	length;
	
	d = va_arg(args, unsigned int);
	tmp = ft_itoa_x(d, 'X');
	width = ft_strlen(tmp);
	length = ft_strlen(tmp);
/*	if (flags->v_width > 0 || flags->b_star_width == 1)
		width = ft_width(flags, args);
	if (flags->b_precision == 1)
		length = ft_length(flags, args);*/
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
	//if (width < ft_strlen(tmp))
	//	width = ft_strlen(tmp);
	//if (length < ft_strlen(tmp))
	//	length = ft_strlen(tmp);
	if (!(tmp1 = malloc(sizeof(char) * (width + 1))))
	{
		free(tmp);
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
	//ft_putnbr_fd(d, 1);
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
	free(tmp1);
	free(tmp2);
	free(tmp);
	return (1);
}
