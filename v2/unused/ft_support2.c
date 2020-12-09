/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:24:39 by jacher            #+#    #+#             */
/*   Updated: 2020/12/09 16:38:30 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include <stdio.h>

char			*ft_strdup_pf(const char *s, unsigned int start, unsigned int stop)
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

char			*ft_strjoin_printf(char *s1, char *s2)
{
	unsigned int	s_s1;
	unsigned int	s_s2;
	char			*tab;
	unsigned int	i;
	unsigned int	j;

	if (!s1 && !s2)
		return (NULL);
	s_s1 = ft_strlen(s1);
	s_s2 = ft_strlen(s2);
	if (!(tab = malloc(sizeof(char) * (s_s1 + s_s2 + 1))))
		return (NULL);
	i = 0;
	while(i < s_s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s_s2 && s2[j])
	{
		tab[i + j] = s2[j];
		j++;
	}
	tab[i + j] = '\0';
	return (tab);
}
