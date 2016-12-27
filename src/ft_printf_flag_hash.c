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

void	ft_printf_flag_hash(t_mod *conv)
{
	size_t	i;
	size_t	j;	
	char	*d;

	d = "0123456789abcdef";
	// printf("0sub->%s\n", conv->substring);
	if (ft_printf_strchri(conv->conversion, 'o', &i) == 1)
	{
		// printf("1conv->precision: %d\n", !(conv->precision));
		// printf("0sub: %s\n", conv->substring);
		// printf("1sub->%s\n", conv->substring);		
		ft_printf_stric(conv->substring, "0", &i);
		ft_printf_stric(conv->substring, d + 1, &j);  
		
		// printf("d + 1: %s\n", d + 1);
		// printf("j: %d\n", j);
		// printf("i: %d\n", i);
		// printf("2sub->%s\n", conv->substring);
		// printf("mfw: %d\n", conv->mfw);
		// printf("mfieldwidth: %s\n", conv->mfieldwidth);		
		if ((i > j || !(conv->precision)) && !(conv->mfieldwidth) && conv->num != 0)
		{
			// printf("3sub->%s\n", conv->substring);
			// printf("1conv->precision: %s\n", conv->precision);
			ft_printf_fstrinsert(&(conv->substring), "0", j, j);				
		}
		else if ((i > j || !(conv->precision)) && conv->mfieldwidth && conv->num != 0)
		{	
			// printf("4sub->%s\n", conv->substring);
			// printf("mfw: %d\n", conv->mfw);
			// printf("mfieldwidth: %s\n", conv->mfieldwidth);
			// printf("j: %d\n", j);
			ft_printf_fstrinsert(&(conv->substring), "0", j - 1, j);
			ft_printf_fstrinsert(&(conv->mfieldwidth), "", 0, 1);
			// printf("check\n");
		}
		// printf("5sub->%s\n", conv->substring);
	
	}
	else if (ft_printf_stric(conv->conversion, "xX", &i) == 1)
	{		
		// printf("2sub: %s\n", conv->substring);
		if (ft_printf_stric(conv->substring, d + 1, &j))
		{		
			// printf("3sub: %s\n", conv->substring);	
			ft_printf_stric(conv->substring, d, &i);
			// if (i > j)
			// {
			// 	printf("i > j: %s\n", conv->substring);
			// 	ft_printf_fstrinsert(&(conv->substring), "0x", i, i);
			// }
			// else 
			// {
			// 	printf("else: %s\n", conv->substring);
			// printf("conv->substring: %s\n", conv->substring);

			if (conv->mfieldwidth)
			{
				// printf("4sub: %s\n", conv->substring);
				if(ft_printf_strlen(conv->mfieldwidth) < 2)
				{
					// printf("i: %d\n", i);
					ft_printf_fstrinsert(&(conv->substring), (conv->conversion[0] == 'x')? "0x" : "0X", i , i);
					// printf("0sub: %s\n", conv->substring);
				}
				else
				{
					// printf("i: %d\n", i);
					// printf("1sub: %s\n", conv->substring);
					ft_printf_fstrinsert(&(conv->substring), (conv->conversion[0] == 'x')? "0x" : "0X", i - 2, i);
					ft_printf_fstrinsert(&(conv->mfieldwidth), "", 0, 2);
					// printf("2sub: %s\n", conv->substring);
				}
			}
			else 
				ft_printf_fstrinsert(&(conv->substring), (conv->conversion[0] == 'x')? "0x" : "0X", 0 , 0);
			
			// printf("5sub: %s\n", conv->substring);
			// printf("sub: %s\n", conv->substring);
			// }
		}
	}
	// printf("6sub: %s\n", conv->substring);
}
