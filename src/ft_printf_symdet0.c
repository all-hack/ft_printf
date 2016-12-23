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

#include "../include/libftprintf.h"

void	ft_printf_symdet_flags(char const **seq, t_mod *conv)
{	
	size_t	delim_index;	
	size_t	i;

	i = 0;
	delim_index = 0;
	if (ft_printf_1chrNsym(*seq, g_flag_symbols, &(conv->flag)) == 1)
	{
		while (i < ft_printf_strlen(conv->flag))
		{
			(*seq)++;
			i++;
		}	
	}
}

void	ft_printf_symdet_mfw(char const **seq, t_mod *conv)
{	
	size_t	delim_index;	
	size_t	i;

	i = 0;
	delim_index = 0;	
	if (ft_printf_1chrNsym(*seq, g_mfieldwidth_symbols, &(conv->mfieldwidth)) == 1)
	{
		while (i < ft_printf_strlen(conv->mfieldwidth))
		{
			(*seq)++;
			i++;
		}	
	}
}

void	ft_printf_symdet_prec(char const **seq, t_mod *conv)
{	
	size_t	delim_index;	
	size_t	i;
	char	*tmp;

	i = 0;
	delim_index = 0;
	tmp = NULL;
	if (ft_printf_1chrNsym(*seq, g_precision_symbols, &tmp) == 1)
	{				
		conv->precision = ft_printf_strdup(tmp + 1);
		
		ft_printf_strdel(&tmp);
		while (i < ft_printf_strlen(conv->precision) + 1)
		{
			(*seq)++;
			i++;
		}		
		// printf("conv->precision: %s\n", conv->precision);
	}
}

void	ft_printf_symdet_length(char const **seq, t_mod *conv)
{	
	size_t	delim_index;	
	size_t	i;

	i = 0;
	delim_index = 0;
	if (ft_printf_Nchr1sym(*seq, g_length_symbols, &(conv->length)) == 1)
	{		
		while (i < ft_printf_strlen(conv->length))
		{
			(*seq)++;
			i++;
		}	
	}

}

void	ft_printf_symdet_conv(char const **seq, t_mod *conv)
{	
	size_t	delim_index;	
	size_t	i;

	i = 0;
	delim_index = 0;	
	if (ft_printf_1chrNsym(*seq, g_conversion_symbols, &(conv->conversion)) == 1)
	{		
		while (i < ft_printf_strlen(conv->conversion))
		{
			(*seq)++;
			i++;
		}	
	}
}
