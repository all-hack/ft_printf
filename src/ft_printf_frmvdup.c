/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 00:08:09 by obelange          #+#    #+#             */
/*   Updated: 2016/11/12 00:08:11 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char static	*copy_ignore_0(char *dst, char **src, size_t len, size_t size)
{
	size_t 	i;
	char	*tmp;

	tmp = *src;
	i = 0;
	while (i < len)
	{
		while (**src)
		{
			dst[i] = **src;
			(*src)++;			
			i++;
		}
		(*src)++; 
	}
	ft_printf_strdel(&tmp);
	return (dst);
}


char	*ft_printf_frmvdup(char	**str, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	x;
	char	c;

	x = 0;
	len = size - 1;
	i = 0;
	while (len > 0)
	{	
		c = **str;	
		if (**str)
		{
			(*str)++;
			while (i < len)
			{	
				if ((*str)[i] == c)
				{					
					x++;
					(*str)[i] = '\0';
				}
				i++;
			}		
			i = 0;			
		}
		else
			(*str)++;
		len--;
	}
	*str = (*str) - (size - 1);	
	return (copy_ignore_0(ft_printf_strnew(size - x), str, size - x, size));
}

