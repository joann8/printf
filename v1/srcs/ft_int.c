/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/07 13:49:13 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include <stdio.h>

void ft_int_left(char *s, char *tmp, unsigned int width)
{
	unsigned int i;

	i = 0;
	while (s[i] && i < width)
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

void ft_int_right(char *s, char *tmp, unsigned int width)
{
	unsigned int i;
	unsigned int j;
	unsigned int dif;

	i = 0;
	dif = 0;
	//if (s[0] == '-')
	//	dif = 1;
	tmp[width] = '\0';
	while (i < width - ft_strlen(s))
	{
		tmp[i] = ' ';
		i++;
	}
	/*if (s[0] == '-')
	{
		tmp[i] = '-';
		i++;
	}*/
	j = 0;
	while (s[j + dif] && i + j < width)
	{
		tmp[i + j] = s[j + dif];
		j++;
	}
}

void ft_int_right_0(char *s, char *tmp, unsigned int width, unsigned int length)
{
	unsigned int i;
	unsigned int j;
	unsigned int dif;

	i = 0;
	dif = 0;
	tmp[width] = '\0';	
	if (s[0] == '-')
		dif = 1;
	while (i + dif < width - length)
	{
		tmp[i] = ' ';
		i++;
	}
	if (s[0] == '-')
	{
		tmp[i] = '-';
		i++;
	}
	while (i < width - ft_strlen(s) + 1)
	{
		tmp[i] = '0';
		i++;
	}
	j = 0;	
	while (s[j + dif] && i + j < width)
	{
		tmp[i + j] = s[j + dif];
		j++;
	}
}

int		ft_unsint(va_list args, char **res, flag_list *flags)
{
	unsigned int	d;
	char			*tmp;
	char			*tmp1;
	char			*tmp2;
	unsigned int	width;
	unsigned int	length;
	
	d = va_arg(args, unsigned int);
	tmp = ft_itoa_unsint(d);
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
/*	width = 1;
	length = 1;*/
/*	if (flags->v_width > 0 || flags->b_star_width == 1)
		width = ft_width(flags, args);
	if (flags->b_precision == 1)
		length = ft_length(flags, args);
	d = va_arg(args, unsigned int);
	tmp = ft_itoa_unsint(d);
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
		free(tmp);
		return (-1); //erreur
	}
	if (flags->b_flag_minus == 1 && flags->v_width != 0)
		ft_int_left(tmp, tmp1, width);
	else
	{
		if (flags->b_flag_zero == 1)	
			ft_int_right_0(tmp, tmp1, width, length);
		else
			ft_int_right(tmp, tmp1, width, length);
	}*/
	//ft_putnbr_fd(d, 1);
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);
	free(tmp2);
	free(tmp1);
	free(tmp);
	return (1);
}

int		ft_int(va_list args, char **res, flag_list *flags)
{
	int				d;
	char			*tmp;
	char			*tmp1;
	char			*tmp2;
	unsigned int	width;
	unsigned int	length;
	
	d = va_arg(args, int);
	tmp = ft_itoa_int(d);
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
/*
	width = 1;
	length = 1;
	if (flags->v_width > 0 || flags->b_star_width == 1)
		width = ft_width(flags, args);
	if (flags->b_precision == 1)
		length = ft_length(flags, args);*/
/*	d = va_arg(args, int);
	tmp = ft_itoa_int(d);
	if (width < ft_strlen(tmp))
		width = ft_strlen(tmp);
	if (length < ft_strlen(tmp)) 
		length = ft_strlen(tmp);
	if (length > width)
	{	
		flags->b_flag_zero = 1;
		if (d < 0)
			width = length + 1;
		else
			width = length;
	}
	if (!(tmp1 = malloc(sizeof(char) * (width + 1))))
	{
		free(tmp);
		return (-1); //erreur
	}
	if (flags->b_flag_minus == 1 && flags->v_width != 0)
		ft_int_left(tmp, tmp1, width);
	else
	{
		if (flags->b_flag_zero == 1)	
			ft_int_right_0(tmp, tmp1, width, length);
		else
			ft_int_right(tmp, tmp1, width, length);
	}*/
	//ft_putnbr_fd(d, 1);
	tmp2 = ft_strjoin_printf(*res, tmp1);
	free(*res);
	*res = ft_strdup(tmp2);	
	free(tmp2);
	free(tmp1);
	free(tmp);
	return (1);
}

