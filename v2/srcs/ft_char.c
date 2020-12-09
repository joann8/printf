/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/09 17:34:48 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_char_right(char car, char *c, unsigned int width, int mod)
{
	unsigned int i;
	char		 fill;

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

static void	ft_char_left(char car, char *c, unsigned int width)
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

void	display_char(char car, unsigned int size, flag_list *flags, char *c)
{
	if (car == '\0')
	{
		if (size > 0)
			ft_char_right(' ', c, size, 1);
	}
	else if (flags->b_flag_minus == 0)
		ft_char_right(car, c, size, 1);	
	else 
		ft_char_left(car, c, size);
}

int		ft_char(va_list args, int *res, flag_list *flags)
{
	char			car;
	char 			*c;
	unsigned int	size;
	
	size = 1;
	c = NULL;
	if(flags->b_flag_zero == 1 || flags->b_precision == 1)
		return ((*res = -1));
	if (flags->b_width == 1 && flags->v_width > 1)
		size = flags->v_width;
//	car = (char)va_arg(args, int);
	if ((car = (char)va_arg(args, int)) == '\0')
		size--;
	if (size > 0 && !(c = malloc(sizeof(char) * (size + 1))))
		return ((*res = -1)); 
	display_char(car, size, flags, c);
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

void	display_percent(char car, unsigned int size, flag_list *flags, char *c)
{	
	if (flags->b_flag_minus == 0)
	{
		if (flags->b_flag_zero == 1)
			ft_char_right(car, c, size, 0);
		else
			ft_char_right(car, c, size, 1);
	}	
	else
		ft_char_left(car, c, size);	
}

int		ft_percent(va_list args, int *res, flag_list *flags)
{
	char			car;
	char			*c;
	unsigned int	size;
	
	(void)args;
	size = 1;
	if(flags->b_precision == 1)
		return ((*res = -1));
	if (flags->b_width == 1 && flags->v_width > 1)
		size = flags->v_width;
	if (!(c = malloc(sizeof(char) * (size + 1))))
	{
		*res = -1;
		return (-1); //erreur
	}
	car = '%';
	display_char(car, size, flags, c);
	ft_putstr(c);
	*res += ft_strlen(c);
	free(c);
	return (1);
}
