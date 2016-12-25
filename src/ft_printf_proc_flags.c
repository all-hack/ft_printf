/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fstrmcat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:00:13 by obelange          #+#    #+#             */
/*   Updated: 2016/11/15 01:00:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"


void	ft_printf_proc_flags(t_mod *conv)
{
	size_t index;
	size_t strt;
	char *s;

	int i = 1;
	// printf("j: %d\n", i++);
	if (conv->flag)
	{
		// printf("1conv->flag: %s\n", conv->flag);
		conv->flag = ft_printf_frmvdup(&(conv->flag), ft_printf_strlen(conv->flag));
		if (ft_printf_strchri(conv->flag, '#', &strt) == 1)
		{
			if (ft_printf_stric(conv->conversion, "cdDipSCscuU", &index) == 1)
				ft_printf_fstrinsert(&(conv->flag), "", strt, strt + 1);		
		}	
		// printf("j: %d\n", i++);
		if (ft_printf_strchri(conv->flag, '0', &strt) == 1)
		{		

			// printf("%s\n", );
			// if (ft_printf_stric(conv->conversion, "sS", &index))
				// conv->cmfw = '0';										
			if (conv->precision || ft_printf_stric(conv->conversion, "sSdDioOuUxXcC", &index) == 1)
			{				
				if (ft_printf_strchri(conv->flag, '-', &index) == 1 || conv->prec > 0)
				{
					// printf("conv->flag: %s\n", conv->flag);		
					ft_printf_fstrinsert(&(conv->flag), "", strt, strt + 1);								
				}
				// else 	// conflict between 0 flag, hashtag, and field width
					// conv->cmfw = '0';		
				else if (ft_printf_stric(conv->conversion, "sS", &index) == 1)
					conv->cmfw = '0';
			}
			// printf("sconv->flag: %s\n", conv->flag);
			
		}	
		// printf("j: %d\n", i++);
		if (ft_printf_strchri(conv->flag, '+', &index) == 1)			
		{					
			if (ft_printf_stric(conv->conversion, "dDi", &strt) == 0) 
				ft_printf_fstrinsert(&(conv->flag), "", index, index + 1);
			if (ft_printf_strchri(conv->flag, ' ', &strt) == 1)		
				ft_printf_fstrinsert(&(conv->flag), "", strt, strt + 1);	
		}	
		else if (ft_printf_strchri(conv->flag, ' ', &strt) == 1)		
		{
			if (ft_printf_stric(conv->conversion, "dDi", &index) == 0)
				ft_printf_fstrinsert(&(conv->flag), "", strt, strt + 1);		
		}
	}
	// printf("conv->flag: %s\n", conv->flag);
	// printf("end: %d\n", i++);
}


// void	ft_printf_proc_flags(t_mod *conv)
// {
// 	size_t index;
// 	size_t strt;
// 	char *s;

// 	conv->flag = ft_printf_frmvdup(&(conv->flag), ft_printf_strlen(conv->flag));
// 	if (ft_printf_strchri(conv->flag, '#', &strt) == 1)
// 	{
// 		printf("conv->flag: %s\n", conv->flag);
// 		if (ft_printf_stric(conv->conversion, "cdDipSCscuU", &index) == 1)
// 			ft_printf_fstrinsert(&(conv->flag), "", strt, strt + 1);		
// 		printf("conv->flag: %p\n", conv->flag);
// 	}	
// 	printf("conv->flag: %s\n", conv->flag);
// 	if (ft_printf_strchri(conv->flag, '0', &strt) == 1)
// 	{
// 		if (conv->precision || ft_printf_strchri(conv->flag, '-', &index) == 1)
// 			conv->flag = ft_printf_fstrinsert(conv->flag, "", strt, strt + 1);		
// 	}
// 	printf("conv->flag: %s\n", conv->flag);
// 	if (ft_printf_strchri(conv->flag, '+', &index) == 1)			
// 	{	
// 		if (ft_printf_strchri(conv->flag, ' ', &strt) == 1)		
// 			conv->flag = ft_printf_fstrinsert(conv->flag, "", strt, strt + 1);	
// 		if (ft_printf_stric(conv->conversion, "dDi", &strt) == 0)
// 			conv->flag = ft_printf_fstrinsert(conv->flag, "", index, index + 1);	
// 	}	
// 	else if (ft_printf_strchri(conv->flag, ' ', &strt) == 1)		
// 	{
// 		if (ft_printf_stric(conv->conversion, "dDi", &index) == 0)
// 			conv->flag = ft_printf_fstrinsert(conv->flag, "", strt, strt + 1);		
// 	}
// }