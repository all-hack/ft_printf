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

void	ft_printf_app_mfieldwidth(t_mod *conv)
{
	char		*tmp;
	intmax_t	index;
	intmax_t	len;
	size_t		i;

	// printf("conv->cmfw: %c\n", conv->cmfw);
	// printf("conv->mfw: %jd\n", conv->mfw);
	// printf("conv->mfieldwidth: %s\n", conv->mfieldwidth);
	// printf("0substring: -->%s\n", conv->substring);	
	if (conv->mfieldwidth)
	{		
		// printf("1substring: -->%s\n", conv->substring);
		if (ft_printf_stric(conv->conversion, "sSdDioOuUxXcCb%", &i) == 1)
		{	
			// printf("2substring: -->%s\n", conv->substring);
			len = ft_printf_strlen(conv->substring);
			index = -1;								
			ft_printf_strdel(&(conv->mfieldwidth));			
			if ((conv->mfw - len) > 0)
			{	
				// printf("3substring: -->%s\n", conv->substring);
				while (++index < (conv->mfw - len))
					conv->mfieldwidth = ft_printf_fstrappend(conv->mfieldwidth, conv->cmfw);					
				tmp = conv->substring;						
				conv->substring = ft_printf_strinsert(conv->substring, conv->mfieldwidth, 0, 0);			
				ft_printf_strdel(&tmp);
				// printf("4substring: -->%s\n", conv->substring);
			}
			// printf("5substring: -->%s\n", conv->substring);
		}
		// printf("6substring: -->%s\n", conv->substring);
	}
}
