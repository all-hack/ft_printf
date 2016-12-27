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

void	ft_printf_proc_setchar(char **data, intmax_t *size, char *charcater, va_list *arg, char c)
{
	size_t i;
	if (ft_printf_strchri(*data, '*', &i) == 1)
		*size = va_arg(*arg, int);
	else
		*size = ft_printf_atoi(*data);
	// if (*size <= 0)
		// ft_printf_strdel(data);
	*charcater = c;		
}
