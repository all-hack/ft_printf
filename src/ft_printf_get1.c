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

void	ft_printf_get_u(t_mod *conv, va_list args)
{		
	if (!(conv->length))
		ft_printf_chng_uint(conv, va_arg(args, unsigned int));	
	else if (ft_printf_strcmp(conv->length, "h") == 0)
		ft_printf_chng_ushort(conv, va_arg(args, unsigned int));
	else if (ft_printf_strcmp(conv->length, "j") == 0)
		ft_printf_chng_uintmax_t(conv, va_arg(args, uintmax_t));
	else if (ft_printf_strcmp(conv->length, "l") == 0)		
		ft_printf_chng_ulong(conv, va_arg(args, unsigned long));
	else if (ft_printf_strcmp(conv->length, "z") == 0)		
		ft_printf_chng_size_t(conv, va_arg(args, size_t));
	else if (ft_printf_strcmp(conv->length, "hh") == 0)
		ft_printf_chng_uchar(conv, va_arg(args, unsigned int));
	else if (ft_printf_strcmp(conv->length, "ll") == 0)		
		ft_printf_chng_ulonglong(conv, va_arg(args, unsigned long long));
}

void	ft_printf_get_o(t_mod *conv, va_list args)
{		
	if (!(conv->length))
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned int), 8, 0);	
	else if (ft_printf_strcmp(conv->length, "h") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned int), 8, 0);
	else if (ft_printf_strcmp(conv->length, "j") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args, uintmax_t), 8, 0);
	else if (ft_printf_strcmp(conv->length, "l") == 0)		
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned long), 8, 0);
	else if (ft_printf_strcmp(conv->length, "z") == 0)	
		conv->substring = ft_printf_itoa_base(va_arg(args, size_t), 8, 0);		
	else if (ft_printf_strcmp(conv->length, "hh") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned int), 8, 0);
	else if (ft_printf_strcmp(conv->length, "ll") == 0)		
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned long long), 8, 0);		
}

void	ft_printf_get_x(t_mod *conv, va_list args)
{		
	if (!(conv->length))
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned int), 16, 0);	
	else if (ft_printf_strcmp(conv->length, "h") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned int), 16, 0);
	else if (ft_printf_strcmp(conv->length, "j") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args, uintmax_t), 16, 0);
	else if (ft_printf_strcmp(conv->length, "l") == 0)		
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned long), 16, 0);
	else if (ft_printf_strcmp(conv->length, "z") == 0)	
		conv->substring = ft_printf_itoa_base(va_arg(args, size_t), 16, 0);		
	else if (ft_printf_strcmp(conv->length, "hh") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned int), 16, 0);
	else if (ft_printf_strcmp(conv->length, "ll") == 0)		
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned long long), 16, 0);		
}

void	ft_printf_get_p(t_mod *conv, va_list args)
{		
	char *tmp;
	char *hex;

	hex = "0x";	
	conv->substring = ft_printf_itoa_base(va_arg(args, unsigned long long), 16, 0);		
	tmp = conv->substring;	
	conv->substring = ft_printf_strmcat(hex, conv->substring);	
	ft_printf_strdel(&tmp);
}

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

void	ft_printf_get_S(t_mod *conv, va_list args)
{	
	wchar_t *tmp1;
	intmax_t	size;
	intmax_t	i;

	size = conv->prec;
	i = 0;
	if (!(conv->length))	
	{
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
		// if (*(conv->substring) == '\0')
		// 	ft_printf_fstrinsert(&(conv->substring), "0", 0, 1);
	}		
}