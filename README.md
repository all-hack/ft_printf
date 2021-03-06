# ft_printf
printf for 42

the library has a particular file structure to ease finding shit

* src
	* int		ft_printf(const char *format, ...);
		* receives the string to print, loops through checking for non-processed '%' characters
		* this is where all the globals are kept except for the conversion getter function array
	* string_manipulation
		* search algorithms
			* int	ft_printf_1chr_nsym(char const *s, char const *c, char **s_str)
				* searches `s` for many one character symbols passed to function in `c` and appends the found symbols into `s_str`
				* returns 1 if any symbol is found, 0 if none are found, -1 for error
			* int	ft_printf_nchr_1sym(char const *s, char const **c, char **s_str)
				* searches `s` for any one multi-character symbols passed to function in `c` and appends the found symbols into `s_str`
				* returns 1 if any symbol is found, 0 if none are found, -1 for error
			* int	ft_printf_strchri(char const *s, char const c, size_t *index)
				* searches `s` for character `c` sets `*index` to the position of the character `c` in `s`
				* returns 1 if any symbol is found, 0 if none are found, -1 for error
			* int	ft_printf_stric(char const *s, char const *c, size_t *index)
				* searches `s` for many one character symbols passed to function in `c` and sets `*index` to the position of the first symbol in `c` found in `s`
				* returns 1 if any symbol is found, 0 if none are found, -1 for error

		* char const	*ft_printf_shiftstr(char const *s1, char const *s2)
			* increments `s1` until it has a value not equal to `s2`, returning `s1`
		* void	ft_printf_fstrinsert(char **printit, char *substr, size_t strt, size_t end)
			* inserts `substr` between `strt` and `end` of `*printit` dropping the characters between `strt` and `end` in `*printit`
			* free's `*printit`
		* char	*ft_printf_frmvdup(char	**str, size_t size)
			* removes all duplicates from string `*str`
		* char	*ft_printf_strinsert(char *printit, char *substr, size_t strt, size_t end)
			* inserts `substr` between `strt` and `end` of `*printit` dropping the characters between `strt` and `end` in `*printit`
		* char	*ft_printf_fstrmcat(char *s1, char const *s2)
			* concatenates `s1` and `s2` into a new malloced string which is returned
			* free's `s1`
		* char	*ft_printf_fstrmcat_conv(char *s1, char const *s2, t_mod *conv)
			* concatenates `s1` and `s2` into a new malloced string which is returned
			* uses `ft_printf_strncpy` to copy instead of `ft_printf_strcat` and takes the struct as a parameter
			* intended to cope with null characters on `c`
			* free's `s1`
		* int	ft_printf_putstr(char const *s, t_mod *conv)
			* prints a string to stdout
		* char	*ft_printf_strcat(char *s1, const char *s2)
			* concatenates `s2` into `s1`
		* int	ft_printf_strcmp(const char *s1, const char *s2)
			* compares `s1` to `s2` returns the lexicalgraphic difference between the two
		* char	*ft_printf_strcpy(char *dst, char const *src)
			* copies string `src` into `dst`
		* void	ft_printf_strdel(char **as)
			* free's memory in a safe manner
		* char	*ft_printf_strdup(const char *s1)
			* creates a new malloced string and copies into it the value of `s1`
		* size_t	ft_printf_strlen(const char *s)
			* returns the size of `s`
		* char	*ft_printf_strncpy(char *dst, const char *src, size_t len)
			* copies up to `len` characters from `src` into `dst`
		* char	*ft_printf_strncat(char *s1, unsigned char const *s2, size_t n)
			* concatenates up to `n` characters from `s2` into `s1`
		* char	*ft_printf_strnew(size_t size)
			* a safe way to create a new string
		* char	*ft_printf_strupper(char *str)
			* makes every character in `str` an upper case character
		* 

	* data_transformation
		* data_type_converters
			* void	ft_printf_chng_char(t_mod *conv, signed char num)
				* converts a `signed char` into a `char *` and points `conv->substring` to it
			* void	ft_printf_chng_uchar(t_mod *conv, unsigned char num)
				* converts a `unsigned char` into a `char *` and points `conv->substring` to it
			* void	ft_printf_chng_short(t_mod *conv, short num)
				* converts a `short` into a `char *` and points `conv->substring` to it
			* void	ft_printf_chng_ushort(t_mod *conv, unsigned short num)
				* converts a `unsigned short` into a `char *` and points `conv->substring` to it
			* void	ft_printf_chng_int(t_mod *conv, int num)
				* converts a `int` into a `char *` and points `conv->substring` to it
			* void	ft_printf_chng_uint(t_mod *conv, unsigned int num)
				* converts a `unsigned int` into a `char *` and points `conv->substring` to it
			* void	ft_printf_chng_long(t_mod *conv, long num)
				* converts a `long` into a `char *` and points `conv->substring` to it
			* void	ft_printf_chng_ulong(t_mod *conv, unsigned long num)
				* converts a `unsigned long` into a `char *` and points `conv->substring` to it
			* void	ft_printf_chng_size_t(t_mod *conv, size_t num)
				* converts a `size_t` into a `char *` and points `conv->substring` to it
			* void	ft_printf_chng_longlong(t_mod *conv, long long num)
				* converts a `long long` into a `char *` and points `conv->substring` to it
			* void	ft_printf_chng_ulonglong(t_mod *conv, unsigned long long num)
				* converts a `unsigned long long` into a `char *` and points `conv->substring` to it
			* void	ft_printf_chng_intmax_t(t_mod *conv, intmax_t num)
				* converts a `intmax_t` into a `char *` and points `conv->substring` to it
			* void	ft_printf_chng_uintmax_t(t_mod *conv, uintmax_t num)
				* converts a `uintmax_t` into a `char *` and points `conv->substring` to it
			* char	*ft_printf_chng_wchar_t(t_mod *conv, wchar_t chr, char *str)
				* converts a `wchar_t` into a utf-8 `char *` and points `conv->substring` to it
				* uses bit manipulation
		* intmax_t	ft_printf_atoi(char const *str)
			* converts string numbers into a intmax_t
		* char	*ft_printf_itoa_base(uintmax_t num, int base, int neg)
			* converts an integer into a `char *` for any arbritary base
		* char	*ft_printf_itoa(int nb)
			* converts an integer into a `char *` base 10
			* not sure if it works right
		* char	*ft_printf_itoa_binary(uintmax_t num, int size)
			* converts an integer into a `char *` base 2 with a pretty print display for binary

	* conversion_getters
		* void	ft_printf_get_cap_c(t_mod *conv, va_list args)
			* handles the length options of the `C` for `wchar_t` kind of conversion and sets `conv->substring`
		* void	ft_printf_get_c(t_mod *conv, va_list args)
			* handles the length options of the `c` for `char` kind of conversion and sets `conv->substring`
			* length options
				* `l` -> `wchar_t`
		* void	ft_printf_get_b(t_mod *conv, va_list args)
			* handles the length options of the `b` for binary notation kind of conversion and sets `conv->substring`
			* length options
				* h  -> `int`				
				* j  -> `int`
				* l  -> `int`
				* hh -> `int`
		* void	ft_printf_get_cap_d(t_mod *conv, va_list args)
			* handles the length options of the `D` for signed decimal notation of size `long` kind of conversion and sets `conv->substring`			
		* void	ft_printf_get_d(t_mod *conv, va_list args)
			* handles the length options of the `d` for signed decimal notation of size `int` kind of conversion and sets `conv->substring`
				* `hh` --> `signed char`
				* `h`  --> `short`
				* `l`  --> `long`
				* `ll` --> `long long`
				* `j`  --> `intmax_t`
				* `z`  --> argument is of a signed type equivalent to `size_t`
		* void	ft_printf_get_i(t_mod *conv, va_list args)
			* handles the length options of the `i` for signed decimal notation of size `int` kind of conversion and sets `conv->substring`
				* `hh` --> `signed char`
				* `h`  --> `short`
				* `l`  --> `long`
				* `ll` --> `long long`
				* `j`  --> `intmax_t`
				* `z`  --> argument is of a signed type equivalent to `size_t`
		* void	ft_printf_get_cap_o(t_mod *conv, va_list args)
			* handles the length options of the `O` for unsigned octal notation of size `unsigned long` kind of conversion and sets `conv->substring`
				* `hh` --> `unsigned char`
				* `h`  --> `unsigned short`
				* `l`  --> `unsigned long`
				* `ll` --> `unsigned long long`
				* `j`  --> `uintmax_t`
				* `z`  --> `size_t`
		* void	ft_printf_get_o(t_mod *conv, va_list args)
			* handles the length options of the `o` for unsigned octal notation of size `unsigned int` kind of conversion and sets `conv->substring`				
		* void	ft_printf_get_p(t_mod *conv, va_list args)
			* handles the length options of the `p` for pointer value in hex `unsigned long long` kind of conversion and sets `conv->substring`
		* void	ft_printf_get_percent(t_mod *conv, va_list args)
			* sets `conv->substring` to '%'
		* void	ft_printf_get_s(t_mod *conv, va_list args)
			* handles the length options of the `s` for strings of `char *` kind of conversion and sets `conv->substring`
				* `l` --> `wchar_t*`
		* void	ft_printf_get_cap_s(t_mod *conv, va_list args)
			* handles the length options of the `S` for strings of `wchar_t *` kind of conversion and sets `conv->substring`
		* void	ft_printf_get_u(t_mod *conv, va_list args)
			* handles the length options of the `u` for unsigned decimal notation of size `unsigned int` kind of conversion and sets `conv->substring`
				* `hh` --> `unsigned char`
				* `h`  --> `unsigned short`
				* `l`  --> `unsigned long`
				* `ll` --> `unsigned long long`
				* `j`  --> `uintmax_t`
				* `z`  --> `size_t`
		* void	ft_printf_get_cap_u(t_mod *conv, va_list args)
			* handles the length options of the `U` for unsigned decimal notation of size `unsigned long` kind of conversion and sets `conv->substring`
		* void	ft_printf_get_x(t_mod *conv, va_list args)
			* handles the length options of the `x` for unsigned hexadecimal notation of size `unsigned int` kind of conversion and sets `conv->substring`
		* void	ft_printf_get_cap_x(t_mod *conv, va_list args)
			* handles the length options of the `X` for unsigned hexadecimal notation of size `unsigned long` kind of conversion and sets `conv->substring`
				* `hh` --> `unsigned char`
				* `h`  --> `unsigned short`
				* `l`  --> `unsigned long`
				* `ll` --> `unsigned long long`
				* `j`  --> `uintmax_t`
				* `z`  --> `size_t`	

	* modifiers_implementation
		* symbol_detection
			* void	ft_printf_symdet_flags(char **seq, t_mod *conv)
				* detects whether there are flags following the percent sign
				* uses the one character many symbol search algorithm
			* void	ft_printf_symdet_mfw(char **seq, t_mod *conv)
				* detects whether there is a minimum field width following the percent sign
				* uses the one character many symbol search algorithm
			* void	ft_printf_symdet_prec(char **seq, t_mod *conv)
				* detects whether there is a precision following the minimum fieldwidth
				* uses the one character many symbol search algorithm
			* void	ft_printf_symdet_length(char **seq, t_mod *conv)
				* detects whether there is a length modifier following the precision
				* uses the many character one symbol search algorithm
			* void	ft_printf_symdet_conv(char **seq, t_mod *conv)
				* detects whether there is a conversion following the length
				* uses the one character many symbol search algorithm

		* handling
			* void	ft_printf_proc_setchar_prec(t_mod *conv, char chr)
				* sets the value of `conv->prec` to the grabbed number from the ellipsis and sets `conv->cprec` to the appropriate character
			* void	ft_printf_proc_precision(t_mod *conv)
				* handles the core logic of setting what is in the precision buffer in the structure
			* void	ft_printf_proc_mfieldwidth(t_mod *conv)
				* handles the core logic of setting what is in the the minimum field width buffer in the structure
			* void	ft_printf_proc_flags(t_mod *conv)
				* handles the core logic of setting what is in the flag buffer in the structure, including removing duplicates

		* application
			* flags				
				* void	ft_printf_flag_plus(t_mod *conv)
					* handles and applies the logic for the flag +
						* a sign must always be placed before a number produced by a signed conversion
						* overrides a ` ` if both are used
				* void	ft_printf_flag_space(t_mod *conv)
					* handles and applies the logic for the flag ' '
						* `d`, `i`
							* a blank should be left before a positive number produced by a signed conversion
				* void	ft_printf_flag_minus(t_mod *conv)
					* handles and applies the logic for the flag -
						* negative field width flag			
						* padded on right with blanks
						* overrides a `0` if both are given
				* void	ft_printf_flag_0(t_mod *conv)
					* handles and applies the logic for the flag 0
						* zero padding
						* the converted value is padded on the left with zeros instead of blanks
						* if the precision is given with a numeric conversion the `0` flag is ignored
				* void	ft_printf_flag_hash(t_mod *conv)
					* handles and applies the logic for the flag #
						* convert value to an alternate form
						* no effect for `c`, `d`, `i`, `p`, `s`
						* `o`
							* the precision of the number is increased to force the first character of the output string to a zero
						* `x` & `X`
							* non-zero result has the string `0x` prepended to it	



			* void	ft_printf_app_flags(t_mod *conv)
					* infastructure piece that calls the appropriate flag function from the flag function array		
			* void	ft_printf_app_conv(t_mod *conv)
				* infastructure piece that calls the appropriate get function from the conversion function array using the ascii number of a conversion as a look up key
			* void	ft_printf_app_precision(t_mod *conv)
				* reads the instructions from the precision buffer and applies them to the `conv->substring`
			* void	ft_printf_app_mfieldwidth(t_mod *conv)
				* reads the instructions from the minimum fieldwidth buffer and applies them to the `conv->substring`





	* infastructure_helper
		* void		ft_printf_dfree_hack(char **str)
			* free's a double `char *` and sets the pointer to an empty string
		* void		ft_printf_free_struct(t_mod **this)
			* free's the entire structure and calls `va-end` to finish the ellipsis interaction
		* t_mod		*ft_printf_init_struct()
			* initializes the structure
		* void		ft_printf_reset_struct(t_mod **this)
			* resets the elements of the structure to their initial state (except `skipts`)


	* infastructure
		* void ft_printf_flow(char **seq, t_mod *conv, va_list args)
			* iterates through the symbol_detection, handler, and application function arrays
		* void	ft_printf_format_parsing(char const *format, t_mod *conv, va_list args)
			* detects conversion sequences and starts the conversion process



