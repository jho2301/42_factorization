/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:49:05 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/02 01:44:09 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define	TRUE	1
#define	FALSE	0
#define	ERROR	-1
#define	t_bool	int

void			print_str(char *str);
void			print_int(unsigned int number);
void			print_prime_factors(unsigned int number);
int				arg_check(int argc, char *argv[]);
int				validate_string(char *str);
unsigned int	simple_atoui(char *str);
t_bool			is_prime(unsigned int number);
t_bool			is_factor(unsigned int candidate, unsigned int number);

int				main(int argc, char *argv[])
{
	unsigned int	number;

	if (arg_check(argc, argv) == ERROR)
		return (-1);
	number = simple_atoui(argv[1]);
	print_prime_factors(number);
	return (0);
}

int				arg_check(int argc, char *argv[])
{
	if (argc == 1)
		print_str("Please enter a argument.\n");
	else if (2 < argc)
		print_str("Too many arguments. Please enter just 1 argument.\n");
	else if (validate_string(argv[1]) == ERROR)
		print_str("Please enter only numbers\n");
	else if (simple_atoui(argv[1]) < 2)
		print_str("Please enter a valid range. (2 ~ 4294967295)\n");
	else
		return (0);
	return (ERROR);
}

void			print_prime_factors(unsigned int number)
{
	unsigned int	i;

	i = 2;
	while (!is_prime(number))
	{
		if (is_factor(i, number))
		{
			print_int(i);
			while (is_factor(i, number))
				number /= i;
			if (number == 1)
				return ;
			print_str(" ");
		}
		i++;
	}
	print_int(number);
	return ;
}

/*
** Utils
*/

void			print_int(unsigned int number)
{
	if (number == 0)
		return ;
	print_int(number / 10);
	number = number % 10 + '0';
	write(1, &number, 1);
	return ;
}

void			print_str(char *str)
{
	int		str_len;

	str_len = 0;
	while (*(str + str_len))
		str_len++;
	write(1, str, str_len);
}

int				validate_string(char *str)
{
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (*str < '0' && '9' < *str)
		return (ERROR);
	while ('0' <= *str && *str <= '9')
		str++;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str != 0)
		return (ERROR);
	return (0);
}

unsigned int	simple_atoui(char *str)
{
	unsigned int	i;
	unsigned long	result;
	t_bool			is_signed;

	result = 0;
	is_signed = FALSE;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_signed = TRUE;
		str++;
	}
	i = 0;
	while ('0' <= *(str + i) && *(str + i) <= '9')
	{
		result *= 10;
		result += *(str + i) - '0';
		i++;
	}
	if (10 < i || is_signed)
		result = 0;
	return (result);
}

t_bool			is_prime(unsigned int number)
{
	unsigned long i;

	i = 2;
	while (i * i <= number)
	{
		if (is_factor(i, number))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool			is_factor(unsigned int candidate, unsigned int number)
{
	if (number % candidate == 0)
		return (TRUE);
	else
		return (FALSE);
}
