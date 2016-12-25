/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fstrmcat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:00:13 by obelange          #+#    #+#             */
/*   Updated: 2016/11/15 01:00:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

char	*ft_printf_fstrmcat_conv(char *s1, char const *s2, t_mod *conv)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*nstr;
	size_t	i;

	// printf("d->%d\n", s2[0]);	

	if (s1)
		s1_len = ft_printf_strlen(s1);
	else
		s1_len = 0;
	if (s2)
		s2_len = ft_printf_strlen(s2);
	else
		s2_len = 0;	

	nstr = ft_printf_strnew((s1_len + s2_len));

	// printf("nstr: %s\n", nstr);

	ft_printf_strncpy(nstr, s1, s1_len);

	// printf("nstr + s1_len: %d, %c\n", *(nstr + s1_len),  *(nstr + s1_len));
	// printf("nstr + s1_len - 1: %d, %c\n", *(nstr + s1_len - 1),  *(nstr + s1_len - 1));
	// printf("nstr + s1_len - 2: %d, %c\n", *(nstr + s1_len - 2),  *(nstr + s1_len - 2));
	// printf("nstr + s1_len - 3: %d, %c\n", *(nstr + s1_len - 3),  *(nstr + s1_len - 3));
	// printf("nstr + s1_len - 4: %d, %c\n", *(nstr + s1_len - 4),  *(nstr + s1_len - 4));
	// printf("(s1_len + s2_len): %d\n", (s1_len + s2_len));
	ft_printf_strncpy(nstr + s1_len, s2, s2_len);
	
	// printf("(s1_len): %d\n", (s1_len));
	// printf("(s2_len): %d\n", (s2_len));
	// printf("(s1_len + s2_len): %d\n", (s1_len + s2_len));
	// printf("(s1_len + s2_len + 1): %d\n", (s1_len + s2_len + 1));
	// printf("s1: %s\n", s1);
	// printf("nstr: %s\n", nstr);

	// printf("nstr[16]: %d, %c\n", nstr[16], nstr[16]);
	// printf("nstr[17]: %d, %c\n", nstr[17], nstr[17]);
	// printf("nstr[18]: %d, %c\n", nstr[18], nstr[18]);
	// printf("nstr[19]: %d, %c\n", nstr[19], nstr[19]);
	// printf("nstr[20]: %d, %c\n", nstr[20], nstr[20]);
	// printf("nstr[21]: %d, %c\n", nstr[21], nstr[21]);

	ft_printf_strdel(&s1);	
	return (nstr);
}