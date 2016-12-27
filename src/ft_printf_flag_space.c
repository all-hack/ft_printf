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

void	ft_printf_flag_space(t_mod *conv)
{
	size_t	i;
	size_t	j;

	// printf("len flag: %d\n", ft_printf_strlen(conv->flag));
	// printf("conv_>flag:%s\n", conv->flag);

	// printf("conv->substring: %s\n", conv->substring);	
	if (conv->num >= 0)
	{
		// ft_printf_stric(conv->substring, "0123456789", &i);	
		// printf("conv->substring: %s<-\n", conv->substring);
		// printf("(conv->substring)[conv->mfw]: %d\n", (conv->substring)[conv->mfw - 1]);	
		
		// printf("0substring: ->%s\n", conv->substring);
		// printf("mfw: ->%d\n", conv->mfw);
		// printf("mfieldwidth: ->%s<--\n", conv->mfieldwidth);
		


		if (ft_printf_strchri(conv->flag, '0', &i))				
			ft_printf_fstrinsert(&(conv->substring), " ", 0, 1);
		else if (!(conv->mfieldwidth))
			ft_printf_fstrinsert(&(conv->substring), " ", 0, 0);		
		else if (ft_printf_strchri(conv->flag, '-', &i) && ft_printf_strchri(conv->substring, ' ', &i))
		{
				
			ft_printf_fstrinsert(&(conv->substring), "", i, i + 1);
			ft_printf_fstrinsert(&(conv->substring), " ", 0, 0);	
		}

		// if ((conv->substring)[conv->mfw - 1] == ' ' && (conv->substring)[conv->mfw] == ' ')
		// {
		// 	// printf("00substring: ->%s\n", conv->substring);
		// 	ft_printf_fstrinsert(&(conv->substring), "", conv->mfw - 1, conv->mfw);
		// 	// printf("conv->substring: %s\n", conv->substring);
		// }
		// else if ((conv->substring)[conv->mfw] == ' ')
		// {		
		// 	// printf("000substring: ->%s\n", conv->substring);
		// 	ft_printf_fstrinsert(&(conv->substring), "", conv->mfw, conv->mfw + 1);
		// }
	}
	// else if ()
	// ft_printf_fstrinsert(&(conv->mfieldwidth), "", 0, 1);		
	// printf("conv->substring: %s\n", conv->substring);
}
