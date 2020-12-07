/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/07 15:35:22 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_char_right(char car, char *c, unsigned int width, int mod)
{
	unsigned int i;
	char		 fill;
	unsigned int plus;

	plus = 0;
	if (mod == 1)
		fill = ' ';
	else
		fill = '0';
	i = 0;
	c[width] = '\0';	
	if (car == '\0')
	{
		c[width - 2] = '\\';
		c[width - 1] = '0';
		plus = 1;
	}
	else
		c[width - 1] = car;
	while (i < width - 1 - plus)
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
	if (car == '\0')
	{
		c[0] = '\\';
		c[1] = '0';
		i++;
	}
	else
		c[0] = car;
	while (i + 1 < width)
	{	
		c[i + 1] = ' ';
		i++;
	}
}
	
int		ft_char(va_list args, char **res, flag_list *flags)
{
	char			car;
	char 			*c;
	char 			*tmp;
	unsigned int	size;

	size = 1;
	if(flags->b_flag_zero == 1 || flags->b_precision == 1)
		return (-1); //erreur
	/*if (flags->v_width > 1 || flags->b_star_width == 1)
		width = ft_width(flags, args);*/
	if (flags->b_width == 1 && flags->v_width > 1)
		size = flags->v_width;
	car = (char)va_arg(args, int);
	if (car == '\0') // pas sure
		size++;
	if (!(c = malloc(sizeof(char) * (size + 1))))
		return (-1); //erreur
	//	ft_char_right(car, c, size, 1);	
	if (flags->b_flag_minus == 0)
		ft_char_right(car, c, size, 1);	
	else
		ft_char_left(car, c, size);	
	tmp = ft_strjoin_printf(*res, c);
	free(*res);
	*res = ft_strdup(tmp);
	free(c);
	free(tmp);
	return (1);
}

int		ft_percent(va_list args, char **res, flag_list *flags)
{
	char			car;
	char			*c;
	char			*tmp;
	unsigned int	size;
	
	(void)args;
	size = 1;
	if(flags->b_precision == 1)
		return (-1); //erreur
	/*if (flags->v_width > 1 || flags->b_star_width == 1)
		width = ft_width(flags, args);*/
	if (flags->b_width == 1 && flags->v_width > 1)
		size = flags->v_width;
	if (!(c = malloc(sizeof(char) * (size + 1))))
		return (-1); //erreur
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
	tmp = ft_strjoin_printf(*res, c);
	free(*res);
	*res = ft_strdup(tmp);
	free(tmp);
	free(c);
	return (1);
}
