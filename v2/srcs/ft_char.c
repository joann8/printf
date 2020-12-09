/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/09 16:58:49 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void		ft_char_right(char car, char *c, unsigned int width, int mod)
{
	unsigned int	i;
	char			fill;

	if (mod == 1)
		fill = ' ';
	else
		fill = '0';
	i = 0;
	c[width] = '\0';
	c[width - 1] = car;
	while (i < width - 1)
	{
		c[i] = fill;
		i++;
	}
}

void		ft_char_left(char car, char *c, unsigned int width)
{
	unsigned int i;

	i = 0;
	c[width] = '\0';
	c[0] = car;
	while (i + 1 < width)
	{
		c[i + 1] = ' ';
		i++;
	}
}

int			ft_char(va_list args, int *res, flag_list *flags)
{
	char			car;
	char			*c;
	unsigned int	size;

	size = 1;
	c = NULL;
	if (flags->b_flag_zero == 1 || flags->b_precision == 1)
		return ((*res = -1));
	if (flags->b_width == 1 && flags->v_width > 1)
		size = flags->v_width;
	car = (char)va_arg(args, int);
	if (car == '\0')
		size--;
	if (size > 0 && !(c = malloc(sizeof(char) * (size + 1))))
		return ((*res = -1));
	if (car == '\0')
	{
		if (size > 0)
			ft_char_right(' ', c, size, 1);
	}
	else if (flags->b_flag_minus == 0)
		ft_char_right(car, c, size, 1);
	else
		ft_char_left(car, c, size);
	if (car == '\0' && flags->b_flag_minus == 1)
		write(1, "\0", 1);
	if (size != 0)
	{
		ft_putstr(c);
		*res += ft_strlen(c);
		free(c);
	}
	if (car == '\0' && flags->b_flag_minus == 0)
		write(1, "\0", 1);
	if (car == '\0')
		*res += 1;
	return (1);
}

int			ft_percent_flag(flag_list *flags, unsigned int *size)
{
	if (flags->b_precision == 1)
		return (-1);
	if (flags->b_width == 1 && flags->v_width > 1)
		*size = flags->v_width;
	return (1);
}
	
int			ft_percent(va_list args, int *res, flag_list *flags)
{
	char			car;
	char			*c;
	unsigned int	size;

	(void)args;
	size = 1;
	if ((ft_percent_flag(flags, &size) == -1))
		return ((*res = -1));
	if (!(c = malloc(sizeof(char) * (size + 1))))
		return ((*res = -1));
	car = '%';
	if (flags->b_flag_minus == 0)
	{
		if (flags->b_flag_zero == 1)
			ft_char_right(car, c, size, 0);
		else
			ft_char_right(car, c, size, 1);
	}
	else
		ft_char_left(car, c, size);
	ft_putstr(c);
	*res += ft_strlen(c);
	free(c);
	return (1);
}
