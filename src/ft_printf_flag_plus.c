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

void	ft_printf_flag_plus(t_mod *conv)
{
	size_t	i;
	size_t	j;
	size_t	len;

	// printf("len flag: %d\n", ft_printf_strlen(conv->flag));
	// printf("conv_>flag:%s\n", conv->flag);

	// printf("conv->substring: %s\n", conv->substring);
	if (conv->num >= 0)
	{
		if (conv->mfieldwidth)
			len = ft_printf_strlen(conv->mfieldwidth);
		else 
			len = 1;

		// printf("mfw: %d\n", conv->mfw);
		ft_printf_stric(conv->substring, "0123456789", &i);	
		// printf("conv->substring: %s<-\n", conv->substring);
		// printf("(conv->substring)[conv->mfw]: %d\n", (conv->substring)[conv->mfw - 1]);	
		// printf("0conv->substring:-->%s\n", conv->substring);
		if (ft_printf_strchri(conv->flag, '0', &i))				
		{
			// printf("-1conv->substring:-->%s\n", conv->substring);
			ft_printf_fstrinsert(&(conv->substring), "+", 0, 1);
		}
		else if (!(conv->mfieldwidth) || ft_printf_strchri(conv->flag, '-', &i))
			{
				// printf("-2conv->substring:-->%s\n", conv->substring);
			ft_printf_fstrinsert(&(conv->substring), "+", 0, 0);	
			}
		// printf("00conv->substring:-->%s\n", conv->substring);
		// printf("(conv->substring)[%d]:-->%c, %d\n", conv->mfw, (conv->substring)[conv->mfw],(conv->substring)[conv->mfw]);
		// if ((conv->substring)[conv->mfw - 1] == ' ' && (conv->substring)[conv->mfw] == ' ')
		// {
		// 	printf("000conv->substring:-->%s\n", conv->substring);
		// 	ft_printf_fstrinsert(&(conv->substring), "", conv->mfw - 1, conv->mfw);
		// 	// printf("conv->substring: %s\n", conv->substring);
		// }
		// else if ((conv->substring)[conv->mfw] == ' ')
		// {		
		// 	printf("0000conv->substring:-->%s\n", conv->substring);
		// 	ft_printf_fstrinsert(&(conv->substring), "", conv->mfw, conv->mfw + 1);
		// 	printf("you will never see me\n");
		// }
		if ((conv->substring)[len - 1] == ' ')
		{
			// printf("00000conv->substring:-->%s\n", conv->substring);
			ft_printf_fstrinsert(&(conv->substring), "+", len - 1, len);	
		}
		else if (ft_printf_strchri(conv->flag, '-', &i) && ft_printf_strchri(conv->flag, ' ', &i)) 
			{
				// printf("00000conv->substring:-->%s\n", conv->substring);
			ft_printf_fstrinsert(&(conv->substring), "+", i, i + 1);	
			}
		else if (ft_printf_strchri(conv->substring, ' ', &i))
		{
			// printf("afafd\n");
			ft_printf_fstrinsert(&(conv->substring), "", i, i + 1);	
		}
	}
	// else if ()
	// ft_printf_fstrinsert(&(conv->mfieldwidth), "", 0, 1);		
	// printf("conv->substring: %s\n", conv->substring);
}
