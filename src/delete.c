/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arrayC.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:48:00 by obelange          #+#    #+#             */
/*   Updated: 2016/09/30 14:48:00 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libftprintf.h"

// /*
// ** %
// */
// void	(*g_printf_get[90]) (t_mod *conv, va_list args) = {

//     ft_printf_get_percent, // %
//     0, /*   &   */
//     0, /*   '   */
//     0, /*   (   */
//     0, /*   )   */
//     0, /*   *   */
//     0, /*   +   */
//     0, /*   ,   */
// 	0, /*   -   */
//     0, /*   .   */
//     0, /*   /   */
//     0, /*   0   */
//     0, /*   1   */
//     0, /*   2   */
//     0, /*   3   */
// 	0, /*   4   */
//     0, /*   5   */
//     0, /*   6   */
//     0, /*   7   */
//     0, /*   8   */
//     0, /*   9   */
//     0, /*   :   */
//     0, /*   ;   */
//     0, /*   <   */
// 	0, /*   =   */
//     0, /*   >   */
//     0, /*   ?   */
//     0, /*   @   */    
// 	0, /*	A	*/
// 	0, /*	B	*/
// 	ft_printf_get_c, /*	C	*/
// 	ft_printf_get_cap_d, /*	D	*/
// 	0, /*	E	*/
// 	0, /*	F	*/
// 	0, /*	G	*/
// 	0, /*	H	*/
// 	0, /*	I	*/
// 	0, /*	J	*/
// 	0, /*	K	*/
// 	0, /*	L	*/
// 	0, /*	M	*/
// 	0, /*	N	*/
// 	ft_printf_get_cap_o, /*	O	*/
// 	0, /*	P	*/
// 	0, /*	Q	*/
// 	0, /*	R	*/
// 	ft_printf_get_cap_s, /*	S	*/
// 	0, /*	T	*/
// 	ft_printf_get_U, /*	U	*/
// 	0, /*	V	*/
// 	0, /*	W	*/
// 	ft_printf_get_X, /*	X	*/
// 	0, /*	Y	*/
// 	0, /*	Z	*/
// 	0, /*	[	*/
// 	0, /*	\	*/
// 	0, /*	]	*/
// 	0, /*	^	*/
// 	0, /*	_	*/
// 	0, /*	`	*/
// 	0, /*	a	*/
// 	ft_printf_get_b, /*	b	*/
// 	ft_printf_get_c, /*	c	*/
// 	ft_printf_get_d, /*	d	*/
// 	0, /*	e	*/
// 	0, /*	f	*/
// 	0, /*	g	*/
// 	0, /*	h	*/
// 	ft_printf_get_i, /*	i	*/
// 	0, /*	j	*/
// 	0, /*	k	*/
// 	0, /*	l	*/
// 	0, /*	m	*/
// 	0, /*	n	*/
// 	ft_printf_get_o, /*	o	*/
// 	ft_printf_get_p, /*	p	*/
// 	0, /*	q	*/
// 	0, /*	r	*/
// 	ft_printf_get_s, /*	s	*/
// 	0, /*	t	*/
// 	ft_printf_get_u, /*	u	*/
// 	0, /*	v	*/
// 	0, /*	w	*/
// 	ft_printf_get_x, /*	x	*/
// 	0, /*	y	*/
// 	0, /*	z	*/
// 	0, /*	{	*/
// 	0, /*	|	*/
// 	0, /*	}	*/
// 	0  /*	~	*/	
// };
