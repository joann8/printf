/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:18:21 by jacher            #+#    #+#             */
/*   Updated: 2020/12/07 16:39:42 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void		ft_string_left(char *s, char *tmp, unsigned int width,
								unsigned int length)
{
	unsigned int i;

	i = 0;
	while (s[i] && i < length)
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

static void		ft_string_right(char *s, char *tmp, unsigned int width,
									unsigned int length)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	tmp[width] = '\0';
	while (length + i < width)
	{
		tmp[i] = ' ';
		i++;
	}
	j = 0;
	while (s[j] && j < length)
	{
		tmp[i + j] = s[j];
		j++;
	}
}

int		ft_string(va_list args, char **res, flag_list *flags)
{
	char 			*s;
	char			*tmp;
	//char			*tmp2;
	unsigned int	length;
	unsigned int	width;

	(void)res;
	if (flags->b_flag_zero == 1)
		return (-1); //erreur
	s = va_arg(args, char *);
	if (s == NULL)
		s = ft_strdup("(null)");
	width = ft_strlen(s);
	if (flags->b_width == 1 && width < flags->v_width)
		width = flags->v_width;
	length = ft_strlen(s);
	if (flags->b_precision == 1)
	{
		length = flags->v_length;
		if (flags->b_width == 0)
			width = length;
	}
	/*if (flags->v_width > 0 || flags->b_star_width == 1)
		width = ft_width(flags, args); // cas 0 a gerer? 
	if (flags->b_precision == 1)
		length = ft_length(flags, args);*/
	/*if (width < ft_strlen(s))
		width = ft_strlen(s);
	if (flags->b_precision == 0)
		length = ft_strlen(s);
	if (flags->v_width == 0)
		width = length;*/
	if (!(tmp = malloc(sizeof(char) * (width + 1))))
		return (-1); //erreur >> -1?
	if (flags->b_flag_minus == 1)
		ft_string_left(s, tmp, width, length);
	else
		ft_string_right(s, tmp, width, length);
	ft_putstr(tmp);/*
	tmp2 = ft_strjoin_printf(*res, tmp);
	free(*res);*/
	free(tmp);
	//*res = ft_strdup(tmp2);
	//free(tmp2);
	return (1);
}
