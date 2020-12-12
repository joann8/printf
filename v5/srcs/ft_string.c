/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:18:21 by jacher            #+#    #+#             */
/*   Updated: 2020/12/12 20:13:31 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

char *string_precision(char *s, t_flag *flags)
{
	char 			*tmp;
	unsigned int	length;
	unsigned int	i;

	i = 0;
	length = ft_strlen(s);
	if (flags->b_precision == 1)
		length = flags->v_length;
	if (!(tmp = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (i < length && s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char			*string_null(int *bol, t_flag *flags)
{
	char *s;

	s = ft_strdup("(null)");
	*bol = 1;
	if (flags->b_width == 0 && flags->b_star_length == 1)
		flags->b_precision = 0;
	return (s);
}

int				ft_string(va_list args, int *res, t_flag *flags)
{
	char			*s;
	char			*tmp_p;
	unsigned int	width;
	int				bol;

	bol = 0;
	s = va_arg(args, char *);
	if (s == NULL && ((s = string_null(&bol, flags)) == NULL))
		return (-1);
	if ((tmp_p = string_precision(s, flags)) == NULL)
	{
		if (bol == 1)
			free(s);
		return ((*res = -1));
	}
	width = ft_strlen(s);
	if (flags->b_width == 1)
		width = flags->v_width;
	else if (flags->b_precision == 1 && flags->v_length < width)
		width = flags->v_length;
	if (flags->b_flag_minus == 1)
	{
		ft_putstr(tmp_p);
		while (width > ft_strlen(tmp_p))
		{
			write(1, " ", 1);
			width--;
		}
	}
	else
	{
		while (width > ft_strlen(tmp_p))
		{
			write(1, " ", 1);
			width--;
		}
		ft_putstr(tmp_p);
	}
	*res += width;
	free (tmp_p);
	if (bol == 1)
		free(s);
	return (1);
}
