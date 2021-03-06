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

void	ft_printf_flag_space(t_mod *conv)
{
	size_t	i;
	size_t	j;

	if (conv->num >= 0)
	{
		if (ft_printf_strchri(conv->flag, '0', &i))
			ft_printf_fstrinsert(&(conv->substring), " ", 0, 1);
		else if (!(conv->mfieldwidth))
			ft_printf_fstrinsert(&(conv->substring), " ", 0, 0);
		else if (ft_printf_strchri(conv->flag, '-', &i) &&
			ft_printf_strchri(conv->substring, ' ', &i))
		{
			ft_printf_fstrinsert(&(conv->substring), "", i, i + 1);
			ft_printf_fstrinsert(&(conv->substring), " ", 0, 0);
		}
	}
}
