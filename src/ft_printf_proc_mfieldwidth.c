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

void	ft_printf_proc_mfieldwidth(t_mod *conv)
{
	size_t	num;
	char	fake;

	if (conv->mfieldwidth)
	{
		ft_printf_proc_setchar(&(conv->mfieldwidth), &(conv->mfw),
											&(fake), &(conv->arg_list), '^');
	}
}
