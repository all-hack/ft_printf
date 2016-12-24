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

#include "../include/libftprintf.h"
// #include <locale.h>

const char *g_sequence_symbols = "%";
const char *g_flag_symbols = "#0-+ ";
const char *g_mfieldwidth_symbols = "0123456789*";
const char *g_precision_symbols = ".0123456789*";
const char *g_length_symbols[7] = {"h", "l", "j", "z", "hh", "ll", 0};
const char *g_conversion_symbols = "sSpdDioOuUxXcCb%";

// allocating memory to flag
// allocating memory to length
// allocating memory to conversion
// allocating memory to substring

t_mod	*ft_printf_init_struct()
{

	t_mod	*here;
	FT_PRINTF_NULLGUARD(here = (t_mod*)malloc(sizeof(t_mod)));
	here->cmfw 					= ' ';
	here->cprec					= '\0';		
	here->mfw 					= -1;
	here->prec					= -1;		
	here->skips					= 0;		
	here->srt_seq 				= 0;
	here->end_seq 				= 0;
	here->flag					= NULL;
	here->prepend				= NULL;
	here->length				= NULL;
	here->conversion			= NULL;
	here->substring				= NULL;
	here->mfieldwidth			= NULL;
	here->precision				= NULL;	
	return (here);
}

void	ft_printf_free_struct(t_mod **this)
{
	if (this)
	{
		if (*this)
		{
			if ((*this)->flag)
				free((*this)->flag);
			if ((*this)->prepend)
				free((*this)->prepend);
			if ((*this)->length)
				free((*this)->length);
			if ((*this)->conversion)
				free((*this)->conversion);
			if ((*this)->substring)
				free((*this)->substring);
			if ((*this)->mfieldwidth)
				free((*this)->mfieldwidth);
			if ((*this)->precision)
				free((*this)->precision);
			(*this)->mfw 					= -1;
			(*this)->cmfw 					= ' ';
			(*this)->prec					= -1;		
			(*this)->cprec					= '\0';		
			(*this)->skips					= 0;		
			(*this)->srt_seq		 		= 0;
			(*this)->end_seq 				= 0;
			va_end((*this)->arg_list);
			free((*this));

		}
	}
}

void	ft_printf_dfree_hack(char **str)
{
	if (str)
	{
		if (*str)
		{
			free(*str);
			*str = ft_printf_strnew(0);			
		}
	}
	
}

void	ft_printf_reset_struct(t_mod **this)
{
	if (this)
	{
		if (*this)
		{
			if ((*this)->flag)
				ft_printf_dfree_hack(&((*this)->flag));
			if ((*this)->prepend)
				ft_printf_dfree_hack(&((*this)->prepend));
			if ((*this)->length)
				ft_printf_dfree_hack(&((*this)->length));
			if ((*this)->conversion)
				ft_printf_dfree_hack(&((*this)->conversion));
			if ((*this)->substring)
				ft_printf_dfree_hack(&((*this)->substring));
			if ((*this)->mfieldwidth)
				ft_printf_dfree_hack(&((*this)->mfieldwidth));
			if ((*this)->precision)
				ft_printf_dfree_hack(&((*this)->precision));
			(*this)->mfw 					= -1;
			(*this)->skips					= 0;
			(*this)->prec					= -1;
			(*this)->cmfw 					= ' ';
			(*this)->cprec					= '\0';		
			(*this)->srt_seq		 		= 0;
			(*this)->end_seq 				= 0;
		}
	}
}

// char	*ft_printf_sstrnew(char **s_str)
// {
// 	char	*str;
// 	if (s_str)
// 	{		
// 		if ((*s_str))
// 			return (*s_str);
// 		else
// 			str = ft_printf_strnew(0);
// 	}	
// 	return (str);
// }


// char ft_printf_strlast(char const *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (s)
// 	{
// 		while (s[i])
// 		{
// 			i++;
// 		}
// 		return (s[i - 1]);
// 	}
// 	return (0);
// }



void		(*g_printf_parse[6]) (char **seq, t_mod *conv) = {
	ft_printf_symdet_flags, 
	ft_printf_symdet_mfw, 
	ft_printf_symdet_prec, 
	ft_printf_symdet_length, 
	ft_printf_symdet_conv, 
	0
};

void	(*g_printf_get[90]) (t_mod *conv, va_list args)= {
    ft_printf_get_percent, /*   %   */
    0, /*   &   */
    0, /*   '   */
    0, /*   (   */
    0, /*   )   */
    0, /*   *   */
    0, /*   +   */
    0, /*   ,   */
	0, /*   -   */
    0, /*   .   */
    0, /*   /   */
    0, /*   0   */
    0, /*   1   */
    0, /*   2   */
    0, /*   3   */
	0, /*   4   */
    0, /*   5   */
    0, /*   6   */
    0, /*   7   */
    0, /*   8   */
    0, /*   9   */
    0, /*   :   */
    0, /*   ;   */
    0, /*   <   */
	0, /*   =   */
    0, /*   >   */
    0, /*   ?   */
    0, /*   @   */    
	0, /*	A	*/
	0, /*	B	*/
	ft_printf_get_C, /*	C	*/
	ft_printf_get_d, /*	D	*/
	0, /*	E	*/
	0, /*	F	*/
	0, /*	G	*/
	0, /*	H	*/
	0, /*	I	*/
	0, /*	J	*/
	0, /*	K	*/
	0, /*	L	*/
	0, /*	M	*/
	0, /*	N	*/
	ft_printf_get_o, /*	O	*/
	0, /*	P	*/
	0, /*	Q	*/
	0, /*	R	*/
	ft_printf_get_S, /*	S	*/
	0, /*	T	*/
	ft_printf_get_u, /*	U	*/
	0, /*	V	*/
	0, /*	W	*/
	ft_printf_get_X, /*	X	*/
	0, /*	Y	*/
	0, /*	Z	*/
	0, /*	[	*/
	0, /*	\	*/
	0, /*	]	*/
	0, /*	^	*/
	0, /*	_	*/
	0, /*	`	*/
	0, /*	a	*/
	ft_printf_get_b, /*	b	*/
	ft_printf_get_c, /*	c	*/
	ft_printf_get_d, /*	d	*/
	0, /*	e	*/
	0, /*	f	*/
	0, /*	g	*/
	0, /*	h	*/
	ft_printf_get_i, /*	i	*/
	0, /*	j	*/
	0, /*	k	*/
	0, /*	l	*/
	0, /*	m	*/
	0, /*	n	*/
	ft_printf_get_o, /*	o	*/
	ft_printf_get_p, /*	p	*/
	0, /*	q	*/
	0, /*	r	*/
	ft_printf_get_s, /*	s	*/
	0, /*	t	*/
	ft_printf_get_u, /*	u	*/
	0, /*	v	*/
	0, /*	w	*/
	ft_printf_get_x, /*	x	*/
	0, /*	y	*/
	0, /*	z	*/
	0, /*	{	*/
	0, /*	|	*/
	0, /*	}	*/
	0  /*	~	*/	
};






// process function


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

void	ft_printf_proc_precision(t_mod *conv)
{
	size_t	num;

	if (conv->precision)
	{		
		if (ft_printf_stric(conv->conversion, "diouDOU", &num) == 1)
		{	
			// printf("1conv->precision: %s\n", conv->precision);
			ft_printf_proc_setchar(&(conv->precision), &(conv->prec), &(conv->cprec), &(conv->arg_list), '0');			
		}
		else if (ft_printf_strchri(conv->conversion, 'x', &num) == 1)
		{
			// printf("2conv->precision: %s\n", conv->precision);
			ft_printf_proc_setchar(&(conv->precision), &(conv->prec), &(conv->cprec), &(conv->arg_list), '0');
		}
		else if (ft_printf_strchri(conv->conversion, 'X', &num) == 1)
			{
				// printf("3conv->precision: %s\n", conv->precision);
			ft_printf_proc_setchar(&(conv->precision), &(conv->prec), &(conv->cprec), &(conv->arg_list), '0');
			}
		else if (ft_printf_stric(conv->conversion, "sS", &num) == 1)
			{
				// printf("4conv->precision: %s\n", conv->precision);
			ft_printf_proc_setchar(&(conv->precision), &(conv->prec), &(conv->cprec), &(conv->arg_list), '\0');
			}
		else
		{
			// printf("5conv->precision: %s\n", conv->precision);
			ft_printf_proc_setchar(&(conv->precision), &(conv->prec), &(conv->cprec), &(conv->arg_list), '\0');
			ft_printf_strdel(&(conv->precision));
		}

	}
}

void	ft_printf_proc_mfieldwidth(t_mod *conv)
{
	size_t	num;
	char	fake;

	if (conv->mfieldwidth)
	{
		ft_printf_proc_setchar(&(conv->mfieldwidth), &(conv->mfw), &(fake), &(conv->arg_list), '^');					
	}
}

// void	ft_printf_fstrinsert(char **printit, char *substr, size_t strt, size_t end)
// {
// 	char	*tmp;
// 	char	*str;

// 	str = *printit;
// 	tmp = ft_printf_fstrmcat(ft_printf_strsub(str, 0, strt), substr);	
// 	if (*tmp == '\0' && *(str + end) == '\0')		
// 		*printit = NULL;	
// 	else
// 		*printit = ft_printf_fstrmcat(tmp, (str + end));	
// 	ft_printf_strdel(&str);
// }

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

char static	*copy_ignore_0(char *dst, char **src, size_t len, size_t size)
{
	size_t 	i;
	char	*tmp;

	tmp = *src;
	i = 0;
	while (i < len)
	{
		while (**src)
		{
			dst[i] = **src;
			(*src)++;			
			i++;
		}
		(*src)++; 
	}
	ft_printf_strdel(&tmp);
	return (dst);
}


char	*ft_printf_frmvdup(char	**str, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	x;
	char	c;

	x = 0;
	len = size - 1;
	i = 0;
	while (len > 0)
	{	
		c = **str;	
		if (**str)
		{
			(*str)++;
			while (i < len)
			{	
				if ((*str)[i] == c)
				{					
					x++;
					(*str)[i] = '\0';
				}
				i++;
			}		
			i = 0;			
		}
		else
			(*str)++;
		len--;
	}
	*str = (*str) - (size - 1);	
	return (copy_ignore_0(ft_printf_strnew(size - x), str, size - x, size));
}





void		(*g_printf_process[4]) (t_mod *conv) = {ft_printf_proc_precision, ft_printf_proc_mfieldwidth, ft_printf_proc_flags, 0};

//apply functions




char	*ft_printf_strinsert(char *printit, char *substr, size_t strt, size_t end)
{
	char	*tmp;
	char	*str;

	tmp = ft_printf_fstrmcat(ft_printf_strsub(printit, 0, strt), substr);
	if (*tmp || *(printit + end))		
		str = ft_printf_fstrmcat(tmp, (printit + end));
	else
		str = NULL;		
	return(str);
}


void	ft_printf_app_conv(t_mod *conv)
{
	int i;

	if (conv->conversion)
	{		
		i = (conv->conversion)[0] - 37;		
		g_printf_get[i] (conv, conv->arg_list);
	}
	conv->num = ft_printf_atoi(conv->substring);
	// printf("1conv->substring: %s\n", conv->substring);
	// printf("conv->num: %lld\n", conv->num);
}

void	ft_printf_app_precision(t_mod *conv)
{
	char		*tmp;
	size_t		i;
	intmax_t	index;
	intmax_t	len;	

	// printf("conv->cprec: %c\n", conv->cprec);
	// printf("conv->prec: %jd\n", conv->prec);
	// printf("conv->precision: %s\n", conv->precision);

	if (conv->precision)
	{		
		// printf("1conv->substring: %s\n", conv->substring);
		if (ft_printf_stric(conv->conversion, "diouDOUxX", &i) == 1)
		{	
			len = ft_printf_strlen(conv->substring);
			if(ft_printf_strchri(conv->substring, '-', &i) == 1)
				len -= 1;
			index = -1;								
			ft_printf_strdel(&(conv->precision));			
			if ((conv->prec - len) > 0)
			{	
				// printf("2conv->substring: %s\n", conv->substring);
				while (++index < (conv->prec - len))
					conv->precision = ft_printf_fstrappend(conv->precision, conv->cprec);				
				tmp = conv->substring;		
				// printf("conv->precision: %s\n", conv->precision);
				// printf("conv->cprec: %c\n", conv->cprec);
				// printf("3conv->substring: %s\n", conv->substring);	

				if(ft_printf_strchri(conv->substring, '-', &i) == 1)
				{
					// printf("7conv->substring: %s\n", conv->substring);
					conv->substring = ft_printf_strinsert(conv->substring, conv->precision, i + 1, i + 1);			
				}
				else
				{
					// printf("conv->precision: %s\n", conv->precision);
					// printf("8conv->substring: %s\n", conv->substring);
					conv->substring = ft_printf_strinsert(conv->substring, conv->precision, 0, 0);			
					// printf("9conv->substring: %s\n", conv->substring);
				}
				// printf("4conv->substring: %s\n", conv->substring);
				ft_printf_strdel(&tmp);
			}
		}
	}	
}


void	ft_printf_app_mfieldwidth(t_mod *conv)
{
	char		*tmp;
	intmax_t	index;
	intmax_t	len;
	size_t		i;

	// printf("conv->cmfw: %c\n", conv->cmfw);
	// printf("conv->mfw: %jd\n", conv->mfw);
	// printf("conv->mfieldwidth: %s\n", conv->mfieldwidth);

	if (conv->mfieldwidth)
	{		
		if (ft_printf_stric(conv->conversion, "sSdDioOuUxXcCb", &i) == 1)
		{	
			len = ft_printf_strlen(conv->substring);
			index = -1;								
			ft_printf_strdel(&(conv->mfieldwidth));			
			if ((conv->mfw - len) > 0)
			{	
				while (++index < (conv->mfw - len))
					conv->mfieldwidth = ft_printf_fstrappend(conv->mfieldwidth, conv->cmfw);					
				tmp = conv->substring;						
				conv->substring = ft_printf_strinsert(conv->substring, conv->mfieldwidth, 0, 0);			
				ft_printf_strdel(&tmp);
			}
		}
	}
}

void	ft_printf_flag_plus(t_mod *conv)
{
	size_t	i;
	size_t	j;

	// printf("len flag: %d\n", ft_printf_strlen(conv->flag));
	// printf("conv_>flag:%s\n", conv->flag);

	// printf("conv->substring: %s\n", conv->substring);
	if (conv->num >= 0)
	{
		ft_printf_stric(conv->substring, "0123456789", &i);	
		// printf("conv->substring: %s<-\n", conv->substring);
		// printf("(conv->substring)[conv->mfw]: %d\n", (conv->substring)[conv->mfw - 1]);	
			
		if (ft_printf_strchri(conv->flag, '0', &i))				
			ft_printf_fstrinsert(&(conv->substring), "+", 0, 1);
		else
			ft_printf_fstrinsert(&(conv->substring), "+", 0, 0);	
		if ((conv->substring)[conv->mfw - 1] == ' ' && (conv->substring)[conv->mfw] == ' ')
		{
			
			ft_printf_fstrinsert(&(conv->substring), "", conv->mfw - 1, conv->mfw);
			// printf("conv->substring: %s\n", conv->substring);
		}
		else if ((conv->substring)[conv->mfw] == ' ')
		{		
			ft_printf_fstrinsert(&(conv->substring), "", conv->mfw, conv->mfw + 1);
		}
	}
	// else if ()
	// ft_printf_fstrinsert(&(conv->mfieldwidth), "", 0, 1);		
	// printf("conv->substring: %s\n", conv->substring);
}

void	ft_printf_flag_space(t_mod *conv)
{
	size_t	i;
	size_t	j;

	// printf("len flag: %d\n", ft_printf_strlen(conv->flag));
	// printf("conv_>flag:%s\n", conv->flag);

	// printf("conv->substring: %s\n", conv->substring);	
	if (conv->num >= 0)
	{
		ft_printf_stric(conv->substring, "0123456789", &i);	
		// printf("conv->substring: %s<-\n", conv->substring);
		// printf("(conv->substring)[conv->mfw]: %d\n", (conv->substring)[conv->mfw - 1]);	
			   
		if (ft_printf_strchri(conv->flag, '0', &i))				
			ft_printf_fstrinsert(&(conv->substring), " ", 0, 1);
		else
			ft_printf_fstrinsert(&(conv->substring), " ", 0, 0);	
		if ((conv->substring)[conv->mfw - 1] == ' ' && (conv->substring)[conv->mfw] == ' ')
		{
			
			ft_printf_fstrinsert(&(conv->substring), "", conv->mfw - 1, conv->mfw);
			// printf("conv->substring: %s\n", conv->substring);
		}
		else if ((conv->substring)[conv->mfw] == ' ')
		{		
			ft_printf_fstrinsert(&(conv->substring), "", conv->mfw, conv->mfw + 1);
		}
	}
	// else if ()
	// ft_printf_fstrinsert(&(conv->mfieldwidth), "", 0, 1);		
	// printf("conv->substring: %s\n", conv->substring);
}

void	ft_printf_flag_minus(t_mod *conv)
{
	size_t	j;

	j = 0;
	if (conv->mfieldwidth)
	{		
		if (ft_printf_stric(conv->conversion, "p", &j) == 0)
		{
			j = ft_printf_strlen(conv->mfieldwidth);	
			ft_printf_fstrinsert(&(conv->substring), conv->mfieldwidth, conv->mfw, conv->mfw);
			ft_printf_fstrinsert(&(conv->substring), "", 0, j);		
		}
	}
	
}

void	ft_printf_flag_0(t_mod *conv)
{
	size_t	i;	
	size_t	j;

	// if ((ft_printf_stric(conv->precision, "123456789", &i) != 1) && conv->mfieldwidth)
	// printf("conv->precision: %s\n", conv->precision);
	if (!(conv->precision) && conv->mfieldwidth && !(ft_printf_stric(conv->conversion, "sS", &i)))
	{	
		// printf("conv->precision: %s\n", conv->precision);
		i = 0;		
		j = 0;
		j = ft_printf_strlen(conv->mfieldwidth);		
		while ((conv->mfieldwidth)[i])		
			(conv->mfieldwidth)[i++] = '0';
		if (ft_printf_strchri(conv->substring, 'x', &i))
		{				
			// printf("3sub: %s\n", conv->substring);
			// printf("i: %d, j: %d\n", i, j);			
			ft_printf_fstrinsert(&(conv->substring), conv->mfieldwidth, i + 1, i + 1);
			ft_printf_fstrinsert(&(conv->substring), "", 0, j);
			// printf("4sub: %s\n", conv->substring);
		}
		else
			ft_printf_fstrinsert(&(conv->substring), conv->mfieldwidth, 0, j);
	}
}





void	ft_printf_flag_hash(t_mod *conv)
{
	size_t	i;
	size_t	j;	
	char	*d;

	d = "0123456789abcdef";
	// printf("0sub->%s\n", conv->substring);
	if (ft_printf_strchri(conv->conversion, 'o', &i) == 1)
	{
		// printf("1conv->precision: %d\n", !(conv->precision));
		// printf("0sub: %s\n", conv->substring);
		// printf("1sub->%s\n", conv->substring);		
		ft_printf_stric(conv->substring, "0", &i);
		ft_printf_stric(conv->substring, d + 1, &j);  
		
		// printf("d + 1: %s\n", d + 1);
		// printf("j: %d\n", j);
		// printf("i: %d\n", i);
		// printf("2sub->%s\n", conv->substring);
		// printf("mfw: %d\n", conv->mfw);
		// printf("mfieldwidth: %s\n", conv->mfieldwidth);		
		if ((i > j || !(conv->precision)) && !(conv->mfieldwidth) && conv->num != 0)
		{
			// printf("3sub->%s\n", conv->substring);
			// printf("1conv->precision: %s\n", conv->precision);
			ft_printf_fstrinsert(&(conv->substring), "0", j, j);				
		}
		else if ((i > j || !(conv->precision)) && conv->mfieldwidth && conv->num != 0)
		{	
			// printf("4sub->%s\n", conv->substring);
			// printf("mfw: %d\n", conv->mfw);
			// printf("mfieldwidth: %s\n", conv->mfieldwidth);
			// printf("j: %d\n", j);
			ft_printf_fstrinsert(&(conv->substring), "0", j - 1, j);
			ft_printf_fstrinsert(&(conv->mfieldwidth), "", 0, 1);
			// printf("check\n");
		}
		// printf("5sub->%s\n", conv->substring);
	
	}
	else if (ft_printf_stric(conv->conversion, "xX", &i) == 1)
	{		
		// printf("2sub: %s\n", conv->substring);
		if (ft_printf_stric(conv->substring, d + 1, &j))
		{		
			// printf("3sub: %s\n", conv->substring);	
			ft_printf_stric(conv->substring, d, &i);
			// if (i > j)
			// {
			// 	printf("i > j: %s\n", conv->substring);
			// 	ft_printf_fstrinsert(&(conv->substring), "0x", i, i);
			// }
			// else 
			// {
			// 	printf("else: %s\n", conv->substring);
			// printf("conv->substring: %s\n", conv->substring);

			if (conv->mfieldwidth)
			{
				// printf("4sub: %s\n", conv->substring);
				if(ft_printf_strlen(conv->mfieldwidth) < 2)
				{
					// printf("i: %d\n", i);
					ft_printf_fstrinsert(&(conv->substring), (conv->conversion[0] == 'x')? "0x" : "0X", i , i);
					// printf("0sub: %s\n", conv->substring);
				}
				else
				{
					// printf("i: %d\n", i);
					// printf("1sub: %s\n", conv->substring);
					ft_printf_fstrinsert(&(conv->substring), (conv->conversion[0] == 'x')? "0x" : "0X", i - 2, i);
					ft_printf_fstrinsert(&(conv->mfieldwidth), "", 0, 2);
					// printf("2sub: %s\n", conv->substring);
				}
			}
			else 
				ft_printf_fstrinsert(&(conv->substring), (conv->conversion[0] == 'x')? "0x" : "0X", 0 , 0);
			
			// printf("5sub: %s\n", conv->substring);
			// printf("sub: %s\n", conv->substring);
			// }
		}
	}
	// printf("6sub: %s\n", conv->substring);
}

void	(*g_printf_flags[6]) (t_mod *conv) = {ft_printf_flag_hash, ft_printf_flag_0, ft_printf_flag_minus, ft_printf_flag_space, ft_printf_flag_plus, 0};

void	ft_printf_app_flags(t_mod *conv)
{
	int	i;
	char	*flags;
	size_t	j;

	if (conv->flag)
	{
		i = 0;
		flags = "#0- +";
		while (*g_printf_flags[i] != 0)
		{		
			// printf("%s\n", flags);
			// printf("%c\n", flags[i]);
			if (ft_printf_strchri(conv->flag, flags[i], &j))
				(*g_printf_flags[i]) (conv);
			i++;
		}
	}
}





void		(*g_printf_apply[5]) (t_mod *conv) = {ft_printf_app_conv, ft_printf_app_precision, ft_printf_app_mfieldwidth, ft_printf_app_flags, 0};


void ft_printf_flow(char **seq, t_mod *conv, va_list args)
{
	int	i;

	// printf("1 parse\n");
	// printf("conv->substring: %s\n", conv->substring);
	i = 0;
	while (*g_printf_parse[i] != 0)
		(*g_printf_parse[i++]) (seq, conv);	
	// printf("[detection]  conv->flag: %s\n", conv->flag);
	// printf("2 process\n");
	// printf("conv->substring: %s\n", conv->substring);
	i = 0;	
	while (*g_printf_process[i] != 0)
	{
		// printf("i: %d\n", i);
		(*g_printf_process[i++]) (conv);
	}
	// printf("[processing] conv->flag: %s\n", conv->flag);
	// printf("3 apply\n");
	// printf("conv->substring: %s\n", conv->substring);
	i = 0;
	while (*g_printf_apply[i] != 0)	
	{
		// printf("i: %d\n", i);
		// printf("conv->substring: %s\n", conv->substring);
		(*g_printf_apply[i++]) (conv);		
	}
	// printf("4\n");
	// printf("conv->substring: %s\n", conv->substring);
}



void	ft_printf_format_parsing(char const *format, t_mod *conv, va_list args)
{	
	char	*fsub;
	char	*rem;

	if (conv)
	{		
		ft_printf_stric(format, g_sequence_symbols, &(conv->srt_seq));
		ft_printf_stric(&((format)[conv->srt_seq + 1]), g_conversion_symbols, &(conv->end_seq));
		fsub = ft_printf_strsub(format, conv->srt_seq + 1, conv->end_seq + 1);
		conv->end_seq += conv->srt_seq + 1;		
		ft_printf_flow(&fsub, conv, args);


		// printf("conv->cmfw: %c\n", conv->cmfw);
		// printf("conv->mfw: %jd\n", conv->mfw);
		// printf("conv->mfieldwidth: %s\n", conv->mfieldwidth);

	}
}




int	ft_printf(const char *format, ...)
{
	t_mod	*conv;
	char	*printit;
	size_t	curr;
	size_t	index;
	char	*tmp;

	curr = 0;	
	if (!(conv = ft_printf_init_struct()))
			return (-1);		
	va_start(conv->arg_list, format);
	printit = NULL;
	while (ft_printf_stric((format + curr), g_sequence_symbols, &index) == 1)
	{
		ft_printf_format_parsing(format + curr, conv, conv->arg_list);
		tmp = ft_printf_strsub(format, curr, conv->srt_seq);		
		printit = ft_printf_fstrmcat(printit, tmp);		
		printit = ft_printf_fstrmcat(printit, conv->substring);
		curr = (conv->end_seq - conv->srt_seq) + curr + ft_printf_strlen(tmp) + 1;
		ft_printf_strdel(&tmp);
		ft_printf_reset_struct(&conv);
	}	
	if (format[curr])
		printit = ft_printf_fstrmcat(printit, format + curr);		
	ft_printf_free_struct(&conv);	
	return (ft_printf_putstr(printit));
}








// int	main()
// {	
// 	printf("\n\n\n");
	
// 	// setlocale( LC_ALL, "");
// 	// char s[9] =  {'s', '4', 's', '5', '6', '5', '2', '3', '\0'};
// 	char *s;
// 	char *s0 = "this is a plain string";
// 	// "h", "l", "j", "z", "hh", "ll"
// 	//h, j, l, hh
// 	char *s1 = "ft_printf->%*d\n";
// 	char *s2 = "this is string number";
// 	char *s3 = "we call this one %s";	
// 	short k = 270;
// 	intmax_t f = -4;

// 	// kills malloc	
// 	//    printf("-->%#08x<--", 42);
// 	// ft_printf("-->%#08x<--", 42);
// 	// seg fault
// 	//    printf("   printf: %%+d->%+d\n", 99);	
// 	// ft_printf("ft_printf: %%+d->%+d\n", 99);	


// 	// test 44
// 	// conflict between 0 flag, hashtag, and field width
// 	// ft_printf("ft_printf: -->%#08x<--\n", 42);	
// 	   // printf("   printf: -->%#08x<--\n", 42);
	

// 	// test 0104 
// 	// intmax + 1 should be a flipped d
//   	// ft_printf("ft_printf: -->%d<--\n", 2147483648);	
// 	  //  printf("   printf: -->%d<--\n", 2147483648);  

// 	// test 0087
// 	// breaks malloc hash and fieldwidth modifiers
//   	// ft_printf("ft_printf: -->%#6o<--\n", 2500);
// 	   // printf("   printf: -->%#6o<--\n", 2500);  	
		
// 	// test 0088
//     // breaks malloc hash and fieldwidth modifiers
//   	// ft_printf("ft_printf: -->%-#6o<--\n", 2500);
//   	   // printf("   printf: -->%-#6o<--\n", 2500);  

//  	// test 0095 	
//  	// break malloc hash and 0
// 	// ft_printf("ft_printf: -->%#.o %#.0o<--\n", 0, 0);  	   
//   	   // printf("   printf: -->%#.o %#.0o<--\n", 0, 0);    

// 	// test 0059
// 	// ft_printf("ft_printf: -->%10s is a string<--\n", "");  	   
//   	   // printf("   printf: -->%10s is a string<--\n", "");    		  

// 	// // test 0060
// 	// ft_printf("ft_printf: -->%.2s is a string<--\n", "");  	   
//  //  	   printf("   printf: -->%.2s is a string<--\n", "");    		  	  

// 	// // test 0061
// 	// ft_printf("ft_printf: -->%5.2s is a string<--\n", "");  	   
//  //  	   printf("   printf: -->%5.2s is a string<--\n", "");    		  	  

// 	// // test 0065
// 	// ft_printf("ft_printf: -->%-10s is a string<--\n", "");  	   
//  //  	   printf("   printf: -->%-10s is a string<--\n", "");    		  	  


// 	// // test 0066
// 	// ft_printf("ft_printf: -->%-.2s is a string<--\n", "");  	   
//  //  	   printf("   printf: -->%-.2s is a string<--\n", "");    		  	  


// 	// // test 0067
// 	// ft_printf("ft_printf: -->%-5.2s is a string<--\n", "");  	   
//  //  	   printf("   printf: -->%-5.2s is a string<--\n", "");    		  	  


// 	// ft_printf("ft_printf->%% 4i 42 == |% 4i|\n", 42);
// 	//    printf("   printf->%% 4i 42 == |% 4i|\n", 42);
// 	// ft_printf("ft_printf->%%04.2i 42 == |%04.2i|\n", 42);
// 	//    printf("   printf->%%04.2i 42 == |%04.2i|\n", 42);
// 	// ft_printf("ft_printf->Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");
// 	//    printf("   printf->Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");




// 	// my problem children
// 	// ft_printf("ft_printf: #- +2d->%#- +2d<-\n", 17);	
// 	// printf("   printf: #- +2d->%#- +2d<-\n", 17);		
// 	// ft_printf("ft_printf: #- +3d->%#- +3d<-\n", 17);	
// 	// printf("   printf: #- +3d->%#- +3d<-\n", 17);	
// 	// ft_printf("ft_printf: #- +4d->%#- +4d<-\n", 17);	
// 	// printf("   printf: #- +4d->%#- +4d<-\n", 17);	
// 	// ft_printf("ft_printf: #- +10d->%#- +10d<-\n", 17);	
// 	// printf("   printf: #- +10d->%#- +10d<-\n", 17);	

// 	// printf("   printf: %%#d->%#d\n", 99);
// 	// printf("   printf: %%#o->%#o\n", 99);
// 	// printf("   printf: %%#09.o->%#09.o\n", 99);
// 	// printf("   printf: %%#x->%#x\n", -44);		
// 	// printf("   printf: %%#x->%#x\n", 0);		
// 	// printf("   printf: %%#.4x->%#.4x\n", 99);
// 	// printf("   printf: %%#7.3x->%#7.3x\n", 99);
// 	// printf("   printf: %%+#-02.7d->%+#-02.7d<-\n", 99);
//  //    printf("   printf: %%#02.7o->%#02.7o\n", 99);
//  //    printf("   printf:  %%#2.7o->%#2.7o\n", 99);
// 	// printf("   printf: %%#02.7x->%#02.7x\n", 15);	


// 	// printf("numerals mfw\n");
// 	//       printf("   printf: %%d->%d\n", 99);		
// 	//    ft_printf("ft_printf: %%d->%d\n", 99);		
// 	//       printf("   printf: %%#d->%#d\n", 99);
// 	//    ft_printf("ft_printf: %%#d->%#d\n", 99);
// 	//       printf("   printf: %% d->% d\n", 99);	
// 	//    ft_printf("ft_printf: %% d->% d\n", 99);	
// 	//       printf("   printf: %% d->% d\n", -99);	
// 	//    ft_printf("ft_printf: %% d->% d\n", -99);	
// 	//       printf("   printf: %%+d->%+d\n", 99);	
// 	//    ft_printf("ft_printf: %%+d->%+d\n", 99);	
// 	//       printf("   printf: %%+d->%+d\n", -99);
// 	//    ft_printf("ft_printf: %%+d->%+d\n", -99);
// 	//       printf("   printf: %% +d->% +d\n", 99);	
// 	//    ft_printf("ft_printf: %% +d->% +d\n", 99);	
// 	//       printf("   printf: %% +d->% +d\n", -99);						
// 	//    ft_printf("ft_printf: %% +d->% +d\n", -99);						
// 	//       printf("   printf: %%0d->%0d\n", 99);	
// 	//    ft_printf("ft_printf: %%0d->%0d\n", 99);	
// 	//       printf("   printf: %%-0d->%-0d<-\n", 99);	
// 	//    ft_printf("ft_printf: %%-0d->%-0d<-\n", 99);	
// 	//       printf("   printf: %%05d->%05d\n", 99);	
// 	//    ft_printf("ft_printf: %%05d->%05d\n", 99);	
// 	//       printf("   printf: %%05.d->%05.d\n", 99);	
// 	//    ft_printf("ft_printf: %%05.d->%05.d\n", 99);	
// 	//       printf("   printf: %%05.0d->%05.0d\n", 99);	
// 	//    ft_printf("ft_printf: %%05.0d->%05.0d\n", 99);	
// 	//       printf("   printf: %%-05d->%-05d<-\n", 99);	
// 	//    ft_printf("ft_printf: %%-05d->%-05d<-\n", 99);	
// 	//       printf("   printf: %%#-05d->%#-05d<-\n", 99);
// 	//    ft_printf("ft_printf: %%#-05d->%#-05d<-\n", 99);
// 	//       printf("   printf: %% -05d->% -05d<-\n", 99);
// 	//    ft_printf("ft_printf: %% -05d->% -05d<-\n", 99);
// 	//       printf("   printf: %%+-05d->%+-05d<-\n", 99);
// 	//    ft_printf("ft_printf: %%+-05d->%+-05d<-\n", 99);
// 	//       printf("   printf: %%02.7d->%02.7d\n", 99);		
// 	//    ft_printf("ft_printf: %%02.7d->%02.7d\n", 99);		
// 	//       printf("   printf: %%-02.7d->%-02.7d<-\n", 99);	
// 	//    ft_printf("ft_printf: %%-02.7d->%-02.7d<-\n", 99);	
// 	//       printf("   printf: %%#02.7d->%#02.7d\n", 99);		
// 	//    ft_printf("ft_printf: %%#02.7d->%#02.7d\n", 99);		
// 	//       printf("   printf: %%#-02.7d->%#-02.7d<-\n", 99);	
// 	//    ft_printf("ft_printf: %%#-02.7d->%#-02.7d<-\n", 99);	
// 	//       printf("   printf: %% #-02.7d->% #-02.7d<-\n", 99);	
// 	//    ft_printf("ft_printf: %% #-02.7d->% #-02.7d<-\n", 99);	
// 	//       printf("   printf: %%+ #-02.7d->%+ #-02.7d<-\n", 99);	
// 	//    ft_printf("ft_printf: %%+ #-02.7d->%+ #-02.7d<-\n", 99);	
// 	//       printf("   printf: %% +#-02.7d->% +#-02.7d<-\n", 99);	
// 	//    ft_printf("ft_printf: %% +#-02.7d->% +#-02.7d<-\n", 99);	
// 	//       printf("   printf: %%+#-015.7d->%+#-015.7d<-\n", 99);	
// 	//    ft_printf("ft_printf: %%+#-015.7d->%+#-015.7d<-\n", 99);	
// 	//       printf("   printf: %%+-015.7d->%+-015.7d<-\n", 99);	
// 	//    ft_printf("ft_printf: %%+-015.7d->%+-015.7d<-\n", 99);	
// 	//    	printf("\n");

// 	//       printf("   printf: %%o->%o\n", 99);
// 	//    ft_printf("ft_printf: %%o->%o\n", 99);
// 	//       printf("   printf: %%#o->%#o\n", 99);
// 	//    ft_printf("ft_printf: %%#o->%#o\n", 99);
// 	//       printf("   printf: %% o->% o\n", 99);
// 	//    ft_printf("ft_printf: %% o->% o\n", 99);
// 	//       printf("   printf: %% o->% o\n", -99);
// 	//    ft_printf("ft_printf: %% o->% o\n", -99);
// 	//       printf("   printf: %%+o->%+o\n", 99);
// 	//    ft_printf("ft_printf: %%+o->%+o\n", 99);
// 	//       printf("   printf: %%+o->%+o\n", -99);
// 	//    ft_printf("ft_printf: %%+o->%+o\n", -99);
// 	//       printf("   printf: %% +o->% +o\n", 99);
// 	//    ft_printf("ft_printf: %% +o->% +o\n", 99);
// 	//       printf("   printf: %% +o->% +o\n", -99);
// 	//    ft_printf("ft_printf: %% +o->% +o\n", -99);
// 	//       printf("   printf: %%#.3o->%#.3o\n", 99);
// 	//    ft_printf("ft_printf: %%#.3o->%#.3o\n", 99);
// 	//       printf("   printf: %%#3.3o->%#3.3o\n", 99);
// 	//    ft_printf("ft_printf: %%#3.3o->%#3.3o\n", 99);
// 	//       printf("   printf: %%0o->%0o\n", 99);
// 	//    ft_printf("ft_printf: %%0o->%0o\n", 99);
// 	//       printf("   printf: %%-0o->%-0o<-\n", 99);
// 	//    ft_printf("ft_printf: %%-0o->%-0o<-\n", 99);
// 	//       printf("   printf: %%05o->%05o\n", 99);
// 	//    ft_printf("ft_printf: %%05o->%05o\n", 99);
// 	//       printf("   printf: %%-05o->%-05o<-\n", 99);
// 	//    ft_printf("ft_printf: %%-05o->%-05o<-\n", 99);
// 	//       printf("   printf: %%02.7o->%02.7o\n", 99);
// 	//    ft_printf("ft_printf: %%02.7o->%02.7o\n", 99);
// 	//       printf("   printf: %%-02.7o->%-02.7o<-\n", 99);
// 	//    ft_printf("ft_printf: %%-02.7o->%-02.7o<-\n", 99);
// 	//       printf("   printf: %%#02.7o->%#02.7o\n", 99);
// 	//    ft_printf("ft_printf: %%#02.7o->%#02.7o\n", 99);
// 	//       printf("   printf: %%#-02.7o->%#-02.7o<-\n", 99);
// 	//    ft_printf("ft_printf: %%#-02.7o->%#-02.7o<-\n", 99);
// 	//       printf("   printf: %%#+-02.7o->%#+-02.7o<-\n", 99);
// 	//    ft_printf("ft_printf: %%#+-02.7o->%#+-02.7o<-\n", 99);
// 	//       printf("   printf: %%#+-02.3o->%#+-02.3o<-\n", 99);
// 	//    ft_printf("ft_printf: %%#+-02.3o->%#+-02.3o<-\n", 99);
// 	//       printf("   printf: %%# +-02.3o->%# +-02.3o<-\n", 99);
// 	//    ft_printf("ft_printf: %%# +-02.3o->%# +-02.3o<-\n", 99);
// 	//    	printf("\n");


// 	//       printf("   printf: %%x->%x\n", -44);				   
// 	//    ft_printf("ft_printf: %%x->%x\n", -44);				   
// 	//       printf("   printf: %%#x->%#x\n", -44);				   
// 	//    ft_printf("ft_printf: %%#x->%#x\n", -44);				   
// 	//       printf("   printf: %%#x->%#x\n", 0);				   
// 	//    ft_printf("ft_printf: %%#x->%#x\n", 0);				   
// 	//       printf("   printf: %% x->% x\n", 44);				   
// 	//    ft_printf("ft_printf: %% x->% x\n", 44);				   
// 	//       printf("   printf: %% x->% x\n", -44);	
// 	//    ft_printf("ft_printf: %% x->% x\n", -44);	
// 	//       printf("   printf: %%+x->%+x\n", 44);	
// 	//    ft_printf("ft_printf: %%+x->%+x\n", 44);	
// 	//       printf("   printf: %%+x->%+x\n", -44);	
// 	//    ft_printf("ft_printf: %%+x->%+x\n", -44);	
// 	//       printf("   printf: %%+ x->%+ x\n", 44);	
// 	//    ft_printf("ft_printf: %%+ x->%+ x\n", 44);	
// 	//       printf("   printf: %%+ x->%+ x\n", -44);			   
// 	//    ft_printf("ft_printf: %%+ x->%+ x\n", -44);			   
// 	//       printf("   printf: %%#.3x->%#.3x\n", 99);
// 	//    ft_printf("ft_printf: %%#.3x->%#.3x\n", 99);
// 	//       printf("   printf: %%#.3x->%.3x\n", 9);
// 	//    ft_printf("ft_printf: %%#.3x->%.3x\n", 9);
// 	//       printf("   printf: %%#3.3x->%#3.3x\n", 99);
// 	//    ft_printf("ft_printf: %%#3.3x->%#3.3x\n", 99);
// 	//       printf("   printf: %%0x->%0x\n", -44);	
// 	//    ft_printf("ft_printf: %%0x->%0x\n", -44);	
// 	//       printf("   printf: %%-0x->%-0x<-\n", -44);	
// 	//    ft_printf("ft_printf: %%-0x->%-0x<-\n", -44);	
// 	//       printf("   printf: %%05x->%05x\n", 15);
// 	//    ft_printf("ft_printf: %%05x->%05x\n", 15);
// 	//       printf("   printf: %%-05x->%-05x<-\n", 15);
// 	//    ft_printf("ft_printf: %%-05x->%-05x<-\n", 15);
// 	//       printf("   printf: %%02.7x->%02.7x\n", 15);				   
// 	//    ft_printf("ft_printf: %%02.7x->%02.7x\n", 15);				   
// 	//       printf("   printf: %%-02.7x->%-02.7x<-\n", 15);	
// 	//    ft_printf("ft_printf: %%-02.7x->%-02.7x<-\n", 15);	
// 	//       printf("   printf: %%#02.7x->%#02.7x\n", 15);				   
// 	//    ft_printf("ft_printf: %%#02.7x->%#02.7x\n", 15);				   
// 	//       printf("   printf: %%#-02.7x->%#-02.7x<-\n", 15);		
// 	//    ft_printf("ft_printf: %%#-02.7x->%#-02.7x<-\n", 15);		
//  //   	printf("\n");

// 	// printf("pointer mfw\n");
// 	//       printf("   printf: %%p->%p\n", s0); 	   
// 	//    ft_printf("ft_printf: %%p->%p\n", s0); 	   
// 	//       printf("   printf: %%#p->%#p\n", s0);
// 	//    ft_printf("ft_printf: %%#p->%#p\n", s0);
// 	//       printf("   printf: %% p->% p\n", s0); 
// 	//    ft_printf("ft_printf: %% p->% p\n", s0); 
// 	//       printf("   printf: %%+p->%+p\n", s0); 
// 	//    ft_printf("ft_printf: %%+p->%+p\n", s0); 
// 	//       printf("   printf: %%0p->%0p\n", s0);			
// 	//    ft_printf("ft_printf: %%0p->%0p\n", s0);			
// 	//       printf("   printf: %%-0p->%-0p<-\n", s0);	
// 	//    ft_printf("ft_printf: %%-0p->%-0p<-\n", s0);	
// 	//       printf("   printf: %%05p->%05p\n", s0);	
// 	//    ft_printf("ft_printf: %%05p->%05p\n", s0);	
// 	//       printf("   printf: %%-05p->%-05p<-\n", s0);	
// 	//    ft_printf("ft_printf: %%-05p->%-05p<-\n", s0);	
// 	//       printf("   printf: %%02.7p->%02.7p\n", s0);			
// 	//    ft_printf("ft_printf: %%02.7p->%02.7p\n", s0);			
// 	//       printf("   printf: %%-02.7p->%-02.7p<-\n", s0);	
// 	//     ft_printf("ft_printf: %%-02.7p->%-02.7p<-\n", s0);	
//  //  	printf("\n");


// 	// printf("char mfw\n");
// 	//       printf("   printf: %%c->%c\n", 'f');
// 	//    ft_printf("ft_printf: %%c->%c\n", 'f');
// 	//       printf("   printf: %%#c->%#c\n", 'f');
// 	//    ft_printf("ft_printf: %%#c->%#c\n", 'f');
// 	//       printf("   printf: %% c->% c\n", 'f');
// 	//    ft_printf("ft_printf: %% c->% c\n", 'f');
// 	//       printf("   printf: %%+c->%+c\n", 'f');
// 	//    ft_printf("ft_printf: %%+c->%+c\n", 'f');
// 	//       printf("   printf: %%0c->%0c\n", 'f');	 
// 	//    ft_printf("ft_printf: %%0c->%0c\n", 'f');	 
// 	//       printf("   printf: %%-0c->%-0c<-\n", 'f');	
// 	//    ft_printf("ft_printf: %%-0c->%-0c<-\n", 'f');	
// 	//       printf("   printf: %%07c->%07c\n", 'f');	
// 	//    ft_printf("ft_printf: %%07c->%07c\n", 'f');	
// 	//       printf("   printf: %%-07c->%-07c<-\n", 'f');	
// 	//    ft_printf("ft_printf: %%-07c->%-07c<-\n", 'f');	
// 	//       printf("   printf: %%06.10c->%06.10c\n", 'f');	 
// 	//    ft_printf("ft_printf: %%06.10c->%06.10c\n", 'f');	 
// 	//       printf("   printf: %%-06.10c->%-06.10c<-\n", 'f');	
// 	//    ft_printf("ft_printf: %%-06.10c->%-06.10c<-\n", 'f');	
//  //   	printf("\n");


// 	// printf("char* mfw\n");
// 	//       printf("   printf: %%s->%s\n", "ssss");
// 	//    ft_printf("ft_printf: %%s->%s\n", "ssss");
// 	//       printf("   printf: %%#s->%#s\n", "ssss");
// 	//    ft_printf("ft_printf: %%#s->%#s\n", "ssss");
// 	//       printf("   printf: %% s->% s\n", "ssss");
// 	//    ft_printf("ft_printf: %% s->% s\n", "ssss");
// 	//       printf("   printf: %%+s->%+s\n", "ssss");
// 	//    ft_printf("ft_printf: %%+s->%+s\n", "ssss");
// 	//       printf("   printf: %%0s->%0s\n", "ssss");		
// 	//    ft_printf("ft_printf: %%0s->%0s\n", "ssss");		
// 	//       printf("   printf: %%-0s->%-0s<-\n", "ssss");
// 	//    ft_printf("ft_printf: %%-0s->%-0s<-\n", "ssss");
// 	//       printf("   printf: %%07s->%07s\n", "ssss");	
// 	//    ft_printf("ft_printf: %%07s->%07s\n", "ssss");	
// 	//       printf("   printf: %%-07s->%-07s<-\n", "ssss");	
// 	//    ft_printf("ft_printf: %%-07s->%-07s<-\n", "ssss");	
// 	//       printf("   printf: %%06.10s->%06.10s\n", "ssss");		
// 	//    ft_printf("ft_printf: %%06.10s->%06.10s\n", "ssss");		
// 	//       printf("   printf: %%-06.10s->%-06.10s<-\n", "ssss");		
// 	//    ft_printf("ft_printf: %%-06.10s->%-06.10s<-\n", "ssss");		
//  //   	printf("\n");

	  	
// 	return (0);
// }

