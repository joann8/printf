/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:18:21 by jacher            #+#    #+#             */
/*   Updated: 2020/12/09 18:12:09 by jacher           ###   ########.fr       */
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
	while (i + ft_strlen(s) < width)
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

void	string_help(flag_list *flags, unsigned int *width, unsigned int *length,
						char *s)
{
	*width = ft_strlen(s);
	if (flags->b_width == 1)
		*width = flags->v_width;
	*length = ft_strlen(s);
	if (flags->b_precision == 1)
	{
		*length = flags->v_length;
		if (*length > ft_strlen(s))
		{
			if (*width < ft_strlen(s))
				*width = ft_strlen(s);
		}
		if (*length < ft_strlen(s))
			if (flags->b_width == 0)
				*width = *length;
	}
}

void	display_string(char *tmp, int *res, char *s, int bol)
{
	ft_putstr(tmp);
	*res = ft_strlen(tmp);
	free(tmp);
	if (bol == 1)
		free(s);
}

void	string_null(char *s, int *bol, flag_list *flags)
{
	s = ft_strdup("(null)");
	*bol = 1;
	if (flags->b_width == 0 && flags->b_star_length == 1)
		flags->b_precision = 0;
}

int				ft_string(va_list args, int *res, flag_list *flags)
{
	char			*s;
	char			*tmp;
	unsigned int	length;
	unsigned int	width;
	int				bol;

	bol = 0;
	if (flags->b_flag_zero == 1)
		return ((*res = -1));
	s = va_arg(args, char *);
	if (s == NULL)
		string_null(s, &bol, flags);
	/*
	{
		s = ft_strdup("(null)");
		bol = 1;
		if (flags->b_width == 0 && flags->b_star_length == 1)
			flags->b_precision = 0;
	}*/
	string_help(flags, &width, &length, s);
	if (!(tmp = malloc(sizeof(char) * (width + 1))))
	{
		if (bol == 1)
			free(s);
		return ((*res = 1));
	}
	if (flags->b_flag_minus == 1)
		ft_string_left(s, tmp, width, length);
	else
		ft_string_right(s, tmp, width, length);
	display_string(tmp, res, s, bol);
	return (1);
}
