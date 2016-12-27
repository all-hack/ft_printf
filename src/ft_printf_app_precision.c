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


void	ft_printf_app_precision(t_mod *conv)
{
	char		*tmp;
	size_t		i;
	intmax_t	index;
	intmax_t	len;	

	// printf("conv->cprec: %c\n", conv->cprec);
	// printf("conv->prec: %jd\n", conv->prec);
	// printf("conv->precision: %s\n", conv->precision);

	if (conv->precision)
	{		
		// printf("1conv->substring: %s\n", conv->substring);
		if (ft_printf_stric(conv->conversion, "diouDOUxX", &i) == 1)
		{	
			len = ft_printf_strlen(conv->substring);
			if(ft_printf_strchri(conv->substring, '-', &i) == 1)
				len -= 1;
			index = -1;								
			ft_printf_strdel(&(conv->precision));			
			if ((conv->prec - len) > 0)
			{	
				// printf("2conv->substring: %s\n", conv->substring);
				while (++index < (conv->prec - len))
					conv->precision = ft_printf_fstrappend(conv->precision, conv->cprec);				
				tmp = conv->substring;		
				// printf("conv->precision: %s\n", conv->precision);
				// printf("conv->cprec: %c\n", conv->cprec);
				// printf("3conv->substring: %s\n", conv->substring);	

				if(ft_printf_strchri(conv->substring, '-', &i) == 1)
				{
					// printf("7conv->substring: %s\n", conv->substring);
					conv->substring = ft_printf_strinsert(conv->substring, conv->precision, i + 1, i + 1);			
				}
				else
				{
					// printf("conv->precision: %s\n", conv->precision);
					// printf("8conv->substring: %s\n", conv->substring);
					conv->substring = ft_printf_strinsert(conv->substring, conv->precision, 0, 0);			
					// printf("9conv->substring: %s\n", conv->substring);
				}
				// printf("4conv->substring: %s\n", conv->substring);
				ft_printf_strdel(&tmp);
			}
			if (conv->num == 0 && conv->prec == 0 && conv->mfieldwidth)
				conv->substring = ft_printf_strinsert(conv->substring, " ", 0, 1);
			else if (conv->num == 0 && conv->prec == 0 && !conv->mfieldwidth)
				conv->substring = ft_printf_strinsert(conv->substring, "", 0, 1);
			// printf("substring: -->%s\n", conv->substring);
			// printf("99prec: -->%d\n", conv->prec);
		}
	}	
}

