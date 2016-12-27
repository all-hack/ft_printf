/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strchri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:00:13 by obelange          #+#    #+#             */
/*   Updated: 2016/11/15 01:00:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_get_s(t_mod *conv, va_list args)
{	
	unsigned char *tmp;
	wchar_t *tmp1;
	intmax_t	size;
	intmax_t	i;	

	// printf("1\n");
	size = conv->prec;
	i = 0;	
	if (!(conv->length))
	{
		// printf("2\n");
		tmp = va_arg(args, unsigned char*);
		// printf("tmp: %s\n", tmp);
		// printf("tmp: %c, %d\n", *tmp, *tmp);
		if (size >= 0)
		{
			// printf("5\n");
			conv->substring = ft_printf_fstrappend(conv->substring, tmp[i]);
			while (tmp[i++] && i < size)				
				conv->substring = ft_printf_fstrappend(conv->substring, tmp[i]);			
		}
		else 
		{
			// printf("6\n");
			conv->substring = ft_printf_fstrappend(conv->substring, tmp[i]);
			while (tmp[i++])				
				conv->substring = ft_printf_fstrappend(conv->substring, tmp[i]);
		}		
	}
	else if (ft_printf_strcmp(conv->length, "l") == 0)
	{
		// printf("3\n");
		tmp1 = va_arg(args, wchar_t*);
		if (size >= 0)
		{
			conv->substring = ft_printf_fstrmcat(conv->substring, ft_printf_chng_wchar_t(conv, tmp1[i], NULL));
			while (tmp1[i++] && i < size)	
				conv->substring = ft_printf_fstrmcat(conv->substring, ft_printf_chng_wchar_t(conv, tmp1[i], NULL));
		}
		else 
		{
			conv->substring = ft_printf_fstrmcat(conv->substring, ft_printf_chng_wchar_t(conv, tmp1[i], NULL));	
			while (tmp1[i++])
				conv->substring = ft_printf_fstrmcat(conv->substring, ft_printf_chng_wchar_t(conv, tmp1[i], NULL));	
		}
	}	
	// if (*(conv->substring) == '\0')
			// ft_printf_fstrinsert(&(conv->substring), "0", 0, 1);	
	// printf("4\n");
}
