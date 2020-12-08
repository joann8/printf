/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/08 19:24:34 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include <stdio.h>

void ft_int_left_np(char *s, char *tmp, unsigned int width, unsigned int length)
{
	unsigned int i;

	(void)length;
	i = 0;
	while (s[i] && (i < width))
	{
		tmp[i] = s[i];
		i++;
	}
	while (i < width)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
}

void ft_int_left(char *s, char *tmp, unsigned int width, unsigned int length)
{
	unsigned int i;
	unsigned int j;
	unsigned int dif;
	
	i = 0;
	dif = 0;
	if (s[0] == '-')
	{
		dif = 1;
		tmp[0] = '-';
		i++;
	}
	while (i -dif  < length - ft_strlen(s))
	{
		tmp[i] = '0';
		i++;
	}
	j = 0;
	while (s[j + dif] && j < ft_strlen(s))
	{
		tmp[i] = s[j + dif];
		i++;
		j++;
	}
	while (i < width)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
}

void ft_int_right(char *s, char *tmp, unsigned int width, unsigned int length)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dif;
	char			c;
	
	i = 0;
	dif = 0;
	c = ' ';
	while (i < width - length)
	{
		tmp[i] = ' ';
		i++;
	}
	if (s[0] == '-')
	{
		dif = 1;
		tmp[i] = '-';
		i++;
		c = '0';
	}
	j = 0;
	while (j  < length - ft_strlen(s))
	{	
		tmp[i] = c;
		i++;
		j++;
	}
	j = 0;	
	while (s[j + dif] && (i < length || i < width ))
	{	
		tmp[i] = s[j + dif];
		i++;
		j++;
	}
	tmp[i] = '\0';
}

void ft_int_right_0(char *s, char *tmp, unsigned int width, unsigned int length)
{
	unsigned int i;
	unsigned int j;
	unsigned int dif;

	i = 0;
	dif = 0;
	if (s[0] == '-')
	{
		dif = 1;
		tmp[i] = '-';
		i++;
	}
	j = 0;
	while (j < length - ft_strlen(s))
	{	
		tmp[i] = '0';
		i++;
		j++;
	}
	j = 0;	
	while (s[j + dif] && (i < length || i < width ))
	{	
		tmp[i] = s[j + dif];
		i++;
		j++;
	}
	tmp[i] = '\0';
}

int		ft_unsint(va_list args, int *res, flag_list *flags)
{
	unsigned int	d;
	char			*tmp;
	char			*tmp1;
	unsigned int	width;
	unsigned int	length;
	unsigned int	size;
	
	d = va_arg(args, unsigned int);
	tmp = ft_itoa_unsint(d);	
	if (d == 0 && flags->b_precision == 1 && flags->v_length == 0)
	{
		if (flags->b_width == 1)
			tmp[0] = ' ';
		else
		{
			write(1, "", 0);
			return(1);
		}
	}
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
	if (length > width)
	{
		size = length;
		if (d < 0)
		{
			size++;
			length++;
		}
	}
	else
		size = width;
	if (flags->b_precision == 0)
		length = width;
	if (!(tmp1 = malloc(sizeof(char) * (size + 1))))
	{
		free(tmp);
		*res = -1;
		return (-1); //erreur
	}
	if (flags->b_flag_minus == 1)
	{
		if (flags->b_precision == 0)
			ft_int_left_np(tmp, tmp1, width, length);
		else
			ft_int_left(tmp, tmp1, width, length);
	}
	else
	{
		if (flags->b_flag_zero == 1)	
			ft_int_right_0(tmp, tmp1, width, length);
		else
			ft_int_right(tmp, tmp1, width, length);
	}
	ft_putstr(tmp1);
	*res += ft_strlen(tmp1);
	free(tmp1);
	free(tmp);
	return (1);
}

int		ft_int(va_list args, int *res, flag_list *flags)
{
	int				d;
	char			*tmp;
	char			*tmp1;
	unsigned int	width;
	unsigned int	length;
	unsigned int	size;

	d = va_arg(args, int);	
	tmp = ft_itoa_int(d);
	if (d == 0 && flags->b_precision == 1 && flags->v_length == 0)
	{
		if (flags->b_width == 1)
			tmp[0] = ' ';
		else
		{
			write(1, "", 0);
			return(1);
		}
	}
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
			//width = length;
		}
	}
	if (length > width || (length > ft_strlen(tmp) && width > length))
	{
		if (d < 0)
			length++;
		size = length;
	}
	else
		size = width;
	if (flags->b_flag_zero == 1 && flags->b_precision == 0)
		length = width;
	if (!(tmp1 = malloc(sizeof(char) * (size + 1))))
	{
		free(tmp);
		return ((*res = -1)); //erreur
	}
	if (flags->b_flag_minus == 1)
	{
		if (flags->b_precision == 0)
			ft_int_left_np(tmp, tmp1, width, length);
		else
			ft_int_left(tmp, tmp1, width, length);
	}
	else
	{
		if (flags->b_flag_zero == 1)	
			ft_int_right_0(tmp, tmp1, width, length);
		else
			ft_int_right(tmp, tmp1, width, length);
	}
	ft_putstr(tmp1);
	*res += ft_strlen(tmp1);
	free(tmp1);
	free(tmp);
	return (1);
}

