# ft_printf
printf for 42

the library has a particular file structure to ease finding shit

* src
	* string_manipulation
		* search algorithms
		* char const	*ft_printf_shiftstr(char const *s1, char const *s2)
			* increments `s1` until it has a value not equal to `s2`, returning `s1`

	* data_transformation
	
		* data_type_converters
	
	* conversion_getters
	
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
				
		* processing
	
		* application
