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

void	ft_printf_fstrinsert(char **printit, char *substr, size_t strt, size_t end)
{
	char	*tmp;
	char	*str;
		
	str = *printit;
	tmp = ft_printf_fstrmcat(ft_printf_strsub(str, 0, strt), substr);	
	// printf("tmp: %s\n", tmp);
	// printf("(str + end): %s\n", (str + end));
	// printf("strt: %d\n", strt);
	// printf("end: %d\n", end);	
	if (*tmp == '\0' && *(str + end) == '\0')		
		*printit = NULL;	
	else
		*printit = ft_printf_fstrmcat(tmp, (str + end));	
	
	// printf("*printit: %s\n", *printit);
	ft_printf_strdel(&str);
}
