/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_Nchr1sym.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:00:13 by obelange          #+#    #+#             */
/*   Updated: 2016/11/15 01:00:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_Nchr1sym(char const *s, char const **c, char **s_str)
{
	size_t	i;
	size_t	j;
	size_t	k;	
	char const	*d;
	int		flag;

	if (s && c)
	{
		if (*c)
		{			
			while (*s)
			{
				i = 0;
				
				while (c[i])
				{
					d = c[i];									
					d = ft_printf_shiftstr(d, *s_str);				
					if (ft_printf_1chrNsym(s, d, s_str) == 1)
					{
						s++;
						break;										
					}
					// printf("c: %s\n", c[i]);
					// printf("d: %s\n", d);					
					// printf("conv->length: %s\n", *s_str);
					i++;
				}				
				s++;
			}		
			if (*s_str)
				return (1);
			else 
				return (0);
		}
	}
	return (-1);
}