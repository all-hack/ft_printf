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

void	ft_printf_flag_0(t_mod *conv)
{
	size_t	i;	
	size_t	j;

	// printf("0conv->substring:-->%s\n", conv->substring);
	// if ((ft_printf_stric(conv->precision, "123456789", &i) != 1) && conv->mfieldwidth)
	// printf("conv->precision: %s\n", conv->precision);
	// printf("conv->prec: %d\n", conv->prec);
	if (!(conv->precision) && conv->mfieldwidth && !(ft_printf_stric(conv->conversion, "sS", &i)) && conv->prec < 0)
	{	
		// printf("1conv->substring:-->%s\n", conv->substring);
		// printf("conv->precision: %s\n", conv->precision);
		i = 0;		
		j = 0;
		j = ft_printf_strlen(conv->mfieldwidth);		
		while ((conv->mfieldwidth)[i])		
			(conv->mfieldwidth)[i++] = '0';
		if (ft_printf_strchri(conv->substring, 'x', &i))
		{			
			// printf("2conv->substring:-->%s\n", conv->substring);				
			// printf("3sub: %s\n", conv->substring);
			// printf("i: %d, j: %d\n", i, j);			
			ft_printf_fstrinsert(&(conv->substring), conv->mfieldwidth, i + 1, i + 1);
			ft_printf_fstrinsert(&(conv->substring), "", 0, j);
			// printf("4sub: %s\n", conv->substring);
		}
		else
		{			
			// printf("3conv->substring:-->%s\n", conv->substring);
			if (conv->num < 0)				
			{
				// printf("4conv->substring:-->%s\n", conv->substring);
				ft_printf_strchri(conv->substring, '-', &i);
				// printf("i: %d, j: %d i+j: %d\n",i,j, i + j );
				ft_printf_fstrinsert(&(conv->substring), conv->mfieldwidth, i + 1, i + 1);
				ft_printf_fstrinsert(&(conv->substring), "", 0, j);
			}
			else
			{
				// printf("5conv->substring:-->%s\n", conv->substring);
				ft_printf_fstrinsert(&(conv->substring), conv->mfieldwidth, 0, j);
			}
		}
	}
	// printf("6conv->substring:-->%s\n", conv->substring);
}
