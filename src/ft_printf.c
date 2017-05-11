/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 22:09:28 by obelange          #+#    #+#             */
/*   Updated: 2016/11/13 22:09:30 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char *g_sequence_symbols = "%";
const char *g_flag_symbols = "#0-+ ";
const char *g_mfieldwidth_symbols = "0123456789*";
const char *g_precision_symbols = ".0123456789*";
const char *g_length_symbols[7] = {"h", "l", "j", "z", "hh", "ll", 0};
const char *g_conversion_symbols = "sSpdDioOuUxXcCb%";
void	(*g_printf_parse[6]) (char **seq, t_mod *conv) =
{
	ft_printf_symdet_flags,
	ft_printf_symdet_mfw,
	ft_printf_symdet_prec,
	ft_printf_symdet_length,
	ft_printf_symdet_conv,
	0
};
void	(*g_printf_process[4]) (t_mod *conv) =
{
	ft_printf_proc_mfieldwidth,
	ft_printf_proc_precision,
	ft_printf_proc_flags,
	0
};
void	(*g_printf_flags[6]) (t_mod *conv) =
{
	ft_printf_flag_hash,
	ft_printf_flag_0,
	ft_printf_flag_minus,
	ft_printf_flag_space,
	ft_printf_flag_plus,
	0
};
void	(*g_printf_apply[5]) (t_mod *conv) =
{
	ft_printf_app_conv,
	ft_printf_app_precision,
	ft_printf_app_mfieldwidth,
	ft_printf_app_flags,
	0
};

int	ft_printf(const char *format, ...)
{
	t_mod	*conv;
	char	*printit;
	size_t	curr;
	size_t	index;
	char	*tmp;

	// printf("\nstaring ft_printf format: %s\n", format);
	curr = 0;
	if (!(conv = ft_printf_init_struct()))
		return (-1);
	va_start(conv->arg_list, format);
	printit = NULL;
	while (ft_printf_stric((format + curr), g_sequence_symbols, &index) == 1)
	{
		// printf("\nft_printf loop: 1\n");
		ft_printf_format_parsing(format + curr, conv, conv->arg_list);
		// printf("ft_printf loop: 2\n");
		tmp = ft_printf_strsub(format, curr, conv->srt_seq);
		// printf("ft_printf loop: 3\n");
		printit = ft_printf_fstrmcat(printit, tmp);
		// printf("ft_printf loop: 4\n");
		printit = ft_printf_fstrmcat_conv(printit, conv->substring, conv);
		// printf("ft_printf loop: 5\n");
		curr =
		(conv->end_seq - conv->srt_seq) + curr + ft_printf_strlen(tmp) + 1;
		// printf("ft_printf loop: 6\n");
		ft_printf_strdel(&tmp);
		// printf("ft_printf loop: 7\n");
		ft_printf_reset_struct(&conv);
		// printf("ft_printf loop: 8\n");
	}	
	if (format[curr])
		printit = ft_printf_fstrmcat(printit, format + curr);
	return (ft_printf_putstr(printit, conv));
}
