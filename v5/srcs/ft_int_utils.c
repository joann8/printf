/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/12 21:15:46 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

int		manage_precision_0(t_flag *flags, char *tmp)
{
	if (flags->b_width == 0)
	{
		write(1, "", 0);
		free(tmp);
		return (1);
	}
	else
	{
		tmp[0] = ' ';
		return (0);
	}
}

void	int_format(t_flag *flags, unsigned int *width, unsigned int *length)
{
	if (flags->b_precision == 1 && *length < flags->v_length)
		*length = flags->v_length;
	if (flags->b_width == 1 && *width < flags->v_width)
		*width = flags->v_width;
	if (*width <= *length + flags->b_intneg)
		*width = *length + flags->b_intneg;
}

void	create_int_minus(char *tmp, t_flag *flags, unsigned int width,
							unsigned int length)
{
	if (flags->b_intneg == 1)
	{
		write(1, "-", 1);
		width--;
	}
	while (length > ft_strlen(tmp))
	{
		write(1, "0", 1);
		length--;
		width--;
	}
	ft_putstr(tmp);
	while (width > ft_strlen(tmp))
	{
		write(1, " ", 1);
		width--;
	}
}

void	create_int_right(char *tmp, t_flag *flags, unsigned int width,
							unsigned int length)
{
	if (flags->b_flag_zero == 0)
	{
		while (width > length + flags->b_intneg)
		{
			write(1, " ", 1);
			width--;
		}
	}
	if (flags->b_intneg == 1)
	{
		write(1, "-", 1);
		width--;
	}
	while (width > ft_strlen(tmp))
	{
		write(1, "0", 1);
		width--;
	}
	ft_putstr(tmp);
}
