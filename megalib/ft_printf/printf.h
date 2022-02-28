/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:30:17 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/06 13:38:09 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);

int	ft_putchar_fd(char c, int fd);
int	ft_putendl_fd(char *s, int fd);
int	ft_putnbr_fd(long long n, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putunbr_fd(unsigned long long n, int fd);
int	ft_putnbr_base_fd(long long nb, char *base, int fd);
int	ft_putunbr_base_fd(unsigned long long nb, char *base, int fd);

int	ft_printc(va_list pi, int fd);
int	ft_prints(va_list pi, int fd);
int	ft_printp(va_list pi, int fd);
int	ft_printd(va_list pi, int fd);
int	ft_printu(va_list pi, int fd);
int	ft_printx(va_list pi, int fd);
int	ft_printupperx(va_list pi, int fd);

#endif