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

int	ft_printf_putstr(char const *s)
{
	size_t	len;

	if (s)
	{
		len = ft_printf_strlen(s);	
		write(1, s, len);
	}
	return (len);
}
