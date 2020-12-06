/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/06 15:14:53 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include <stdio.h>

static void	ft_char_right(char car, char *c, unsigned int width)
{
	unsigned int i;

	i = 0;
	c[width] = '\0';
	c[width - 1] = car;
	while (i < width - 1)
	{	
		c[i] = ' ';
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
	
void	ft_char(va_list args, char **res, flag_list *flags)
{
	char			car;
	char 			*c;
	char 			*tmp;
	unsigned int	width;

	width = 1;
	if(flags->b_flag_zero == 1 || flags->b_precision == 1)
		return ; //erreur
	if (flags->v_width > 1 || flags->b_star_width == 1)
		width = ft_width(flags, args);
	if (width == 0)
		width = 1; //erreur? pas sure
	if (!(c = malloc(sizeof(char) * (width + 1))))
	{
		free(*res);
		return; //erreur
	}
	car = (char)va_arg(args, int);
	if (flags->b_flag_minus == 0)
		ft_char_right(car, c, width);	
	else
		ft_char_left(car, c, width);	
	tmp = ft_strjoin_printf(*res, c);
	free(*res);
	*res = ft_strdup(tmp);
	free(c);
	//write(1, &c, 1);u
}

void	ft_percent(va_list args, char **res, flag_list *flags)
{
	char car;
	char *c;
	char *tmp;
	unsigned int	width;
	
	(void)args;
	width = 1;
	if(flags->b_flag_zero == 1 || flags->b_precision == 1)
		return ; //erreur
	if (flags->v_width > 1 || flags->b_star_width == 1)
		width = ft_width(flags, args);
	if (width == 0)
		width = 1; //erreur? pas sure
	if (!(c = malloc(sizeof(char) * (width + 1))))
	{
		free(*res);
		return; //erreur
	}
	car = '%';
	if (flags->b_flag_minus == 0)
		ft_char_right(car, c, width);	
	else
		ft_char_left(car, c, width);	
	tmp = ft_strjoin_printf(*res, c);
	free(*res);
	*res = ft_strdup(tmp);
	//write(1, &c, 1);
}
