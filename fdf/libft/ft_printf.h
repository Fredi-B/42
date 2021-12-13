/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:26:01 by fbechtol          #+#    #+#             */
/*   Updated: 2021/10/13 13:04:31 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ----------------------------- Includes ---------------------------------- */

# include <stdarg.h>
# include "./libft.h"

/*  ------------------------ Function prototypes --------------------------- */

int	ft_printf(const char *str, ...);
int	ft_specifier(char s, va_list ap);
int	ft_print_char(va_list ap);
int	ft_print_percent(void);
int	ft_print_string(va_list ap);
int	ft_print_i_d(int i);
int	ft_print_u(unsigned int i);
int	ft_printf(const char *str, ...);
int	ft_print_x(unsigned int i);
int	ft_print_xx(unsigned int i);
int	ft_print_p(unsigned long long i);

#endif
