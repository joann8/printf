/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:18:21 by jacher            #+#    #+#             */
/*   Updated: 2020/12/10 13:36:29 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void			string_help(flag_list *flags, unsigned int *width,
							unsigned int *length, char *s)
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
		{
			if (flags->b_width == 0 || *width < *length)
				*width = *length;
		}
	}
	else if (*width < ft_strlen(s))
		*width = ft_strlen(s);
}

void			display_string(char *tmp, int *res, char *s, int bol)
{
	ft_putstr(tmp);
	*res += ft_strlen(tmp);
	free(tmp);
	if (bol == 1)
		free(s);
}

char			*string_null(int *bol, flag_list *flags)
{
	char *s;

	s = ft_strdup("(null)");
	*bol = 1;
	if (flags->b_width == 0 && flags->b_star_length == 1)
		flags->b_precision = 0;
	return (s);
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
		s = string_null(&bol, flags);
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
