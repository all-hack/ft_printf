/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 14:13:10 by obelange          #+#    #+#             */
/*   Updated: 2016/10/19 14:13:12 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

int	ft_printf_putstr(char const *s, t_mod *conv)
{
	size_t	len;

	// printf("skips: %d\n", conv->skips);
	// printf("s->%s\n", s);
	len = 0;
	if (s)
	{
		// while ((conv->skips)-- > 0)				
			len += ft_printf_strlen(s);	
		// printf("len: %d\n", len);
		write(1, s, len);
	}
	ft_printf_free_struct(&conv);	
	return (len);
}
