/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:50:18 by jacher            #+#    #+#             */
/*   Updated: 2020/12/09 16:13:35 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

char 	*ft_putadd(void *add)
{
	long			n;
	unsigned long	nb;
	unsigned int	size;
	char			*tab;
	//char			*base;
	
	n = (long)add;
	//base = "0123456789abcdef";
	if (n < 0)
		nb = -n;
	else
		nb = n;
	size = 0;
	if (n == 0)
		size++;
	while (nb > 0)
	{
		size++;
		nb = nb / 16;
	}
	size += 2; //Ox du debut
	if(!(tab = malloc(sizeof(char) * (size + 1))))
		return(NULL);
	tab[size] = '\0';
	tab[0] = '0';
	tab[1] = 'x';
	if (n == 0)
		tab[2] = '0';
	else
		fill_table(n, tab, size, 'a');
	return(tab);
}
