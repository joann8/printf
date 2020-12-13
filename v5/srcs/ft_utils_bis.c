/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:28:28 by jacher            #+#    #+#             */
/*   Updated: 2020/12/13 12:35:30 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

void			ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

size_t			ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strdup(const char *s)
{
	char	*tab;
	int		i;

	if (!(tab = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = s[i];
	return (tab);
}

char			*ft_strdup_pf(const char *s, unsigned int start,
								unsigned int stop)
{
	char	*tab;
	int		i;

	if (!(tab = malloc(sizeof(char) * (stop - start + 1))))
		return (NULL);
	i = 0;
	while (s[i] && i + start < stop)
	{
		tab[i] = s[i + start];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

unsigned int	ft_atoi_printf(const char *str, unsigned int *pos,
								t_flag *flags, int mod)
{
	unsigned int		i;
	unsigned int		res;

	i = 0;
	res = 0;
	while (str[i] == '-')
	{
		if (mod == 1)
		{
			flags->b_flag_minus = 1;
			flags->b_flag_zero = 0;
			i++;
		}
		if (mod == 2)
			return ((flags->b_precision = 0));
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	*pos = *pos + i;
	return (res);
}
