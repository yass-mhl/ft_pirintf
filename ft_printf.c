/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:24:59 by ymehlil           #+#    #+#             */
/*   Updated: 2022/11/17 20:31:50 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(char s, va_list arg)
{
	int	count;

	count = 0;
	if (s == '%')
		count = ft_print_percent();
	else if (s == 'c')
		count = ft_print_char((char)va_arg(arg, int));
	else if (s == 's')
		count = ft_print_str((char *)va_arg(arg, char *));
	else if (s == 'd' || s == 'i')
		count = ft_print_i(arg);
	else if (s == 'u')
		count = ft_print_u(arg);
	else if (s == 'x' || s == 'X')
		count = ft_print_x(s, arg);
	else if (s == 'p')
		count = ft_print_ptr((size_t)va_arg(arg, unsigned long long));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_parse(str[i + 1], arg);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}	
		i++;
	}
	va_end(arg);
	return (count);
}

/*

#include <stdio.h>

int	main()
{
	char *str;
	str = NULL;
	int a = 12.5;
	unsigned int ui_max;
	ui_max = 4294967295;
	
	ft_printf("Test 1 - Pourcentage : %%%\n");
	printf("Test 1 - Verification : %%\n");
	ft_printf("Test 2 - Char : %c\n", 'a');
	printf("Test 2 -Verification : %c\n", 'a');
	ft_printf("Test 3 - String : %s\n", "Salut a toi");
	printf("Test 3 -Verification : %s\n", "Salut a toi");
	ft_printf("Test 4 - String Null : %s\n", str);
	printf("Test 4 -Verification : %s\n", str);
	ft_printf("Test 5 - Decimal Base 10 : %d\n", a);
	printf("Test 5 - Verification : %d\n", a);
	ft_printf("Test 6 - Entier Base 10 : %i\n",1500);
	printf("Test 6 - Verification : %i\n", 1500);
	ft_printf("Test 7 - Unsigned int : %u\n", ui_max);
	printf("Test 7 - Verification : %u\n", ui_max);
	ft_printf("Test 8 - hexadecimal en mini : %x\n", ui_max);
	printf("Test 8 - Verification : %x\n", ui_max);
	ft_printf("Test 9 - hexadecimal en max : %X\n", ui_max);
	printf("Test 9 - Verification : %X\n", ui_max);
}

*/