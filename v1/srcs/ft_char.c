/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:47 by jacher            #+#    #+#             */
/*   Updated: 2020/12/05 21:55:50 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include <stdio.h>

void	ft_percent(va_list args, char **res, flag_list *flags)
{
	char c[2];
	char *tmp;
	
	(void)args;
	(void)flags;

	c[0] = '%';
	c[1] = '\0';
	tmp = ft_strjoin_printf(*res, c);
	free(*res);
	*res = ft_strdup(tmp);
	//write(1, &c, 1);
}

static void	ft_char_right(char *c, va_list args, unsigned int width)
{
	unsigned int i;

	i = 0;
	c[width] = '\0';
	c[width - 1] = (char)va_arg(args, int);
	while (i < width - 1)
	{	
		c[i] = ' ';
		i++;
	}
}

static void	ft_char_left(char *c, va_list args, unsigned int width)
{
	unsigned int i;

	i = 0;
	c[width] = '\0';
	c[0] = (char)va_arg(args, int);
	while (i + 1 < width)
	{	
		c[i + 1] = ' ';
		i++;
	}
}
	
void	ft_char(va_list args, char **res, flag_list *flags)
{
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
	if (flags->b_flag_minus == 0)
		ft_char_right(c, args, width);	
	else
		ft_char_left(c, args, width);	
	tmp = ft_strjoin_printf(*res, c);
	free(*res);
	*res = ft_strdup(tmp);
	free(c);
	//write(1, &c, 1);u
}
