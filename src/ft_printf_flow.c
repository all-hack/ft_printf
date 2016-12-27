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

void ft_printf_flow(char **seq, t_mod *conv, va_list args)
{
	int	i;

	// printf("1 parse\n");
	// printf("conv->substring: %s\n", conv->substring);
	// printf("conv->mfieldwidth: %s\n", conv->mfieldwidth);
	// printf("conv->precision: %s\n", conv->precision);
	// printf("conv->flag: %s\n", conv->flag);
	i = 0;
	while (*g_printf_parse[i] != 0)
		(*g_printf_parse[i++]) (seq, conv);	
	// printf("[detection]  conv->flag: %s\n", conv->flag);
	// printf("2 process\n");
	// printf("conv->substring: %s\n", conv->substring);
	// printf("conv->mfieldwidth: %s\n", conv->mfieldwidth);
	// printf("conv->precision: %s\n", conv->precision);
	// printf("conv->flag: %s\n", conv->flag);
	i = 0;	
	while (*g_printf_process[i] != 0)
	{
		// printf("i: %d\n", i);
		(*g_printf_process[i++]) (conv);
	}
	// printf("[processing] conv->flag: %s\n", conv->flag);
	// printf("3 apply\n");
	// printf("conv->substring: %s\n", conv->substring);
	// printf("conv->mfieldwidth: %s\n", conv->mfieldwidth);
	// printf("conv->precision: %s\n", conv->precision);
	// printf("conv->flag: %s\n", conv->flag);
	i = 0;
	while (*g_printf_apply[i] != 0)	
	{
		// printf("i: %d\n", i);
		// printf("conv->substring: %s\n", conv->substring);
		(*g_printf_apply[i++]) (conv);		
	}
	// printf("4\n");
	// printf("conv->substring: %s\n", conv->substring);
	// printf("conv->mfieldwidth: %s\n", conv->mfieldwidth);
	// printf("conv->precision: %s\n", conv->precision);
	// printf("conv->flag: %s\n", conv->flag);
}
