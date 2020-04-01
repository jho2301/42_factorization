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

#define	ERROR	-1

void			print_str(char *str);
void			print_int(unsigned int number);
void			print_prime_factors(unsigned int number);
int				arg_check(int argc, char *argv[]);
int				is_prime(unsigned int nbr);
int				validate_string(char *str);
unsigned int	simple_atoi(char *str);

int				main(int argc, char *argv[])
{
	unsigned int	number;

	if (arg_check(argc, argv) == ERROR)
		return (-1);
	number = simple_atoi(argv[1]);
	print_prime_factors(number);
	return (0);
}

int				arg_check(int argc, char *argv[])
{
	if (argc != 2)
		print_str("Please input just 1 argument.");
	else if (validate_string(argv[1]) == ERROR)
		print_str("Please enter only numbers");
	else if (simple_atoi(argv[1]) < 2)
		print_str("Please enter a valid range. (2 ~ 4294967295)");
	else
		return (1);
	return (ERROR);
}

void			print_prime_factors(unsigned int number)
{
	unsigned int	factor;

	factor = 2;
	while (number != 1)
	{
		if (number % factor == 0)
		{
			print_int(factor);
			while (number % factor == 0)
				number /= factor;
			if (number != 1)
				print_str(" ");
		}
		else if (is_prime(number))
		{
			print_int(number);
			return ;
		}
		factor++;
	}
}

/*
** Utils
*/

int				is_prime(unsigned int nbr)
{
	unsigned int i;

	i = 2;
	while (i * i <= nbr)
	{
		if (nbr % i == 0){
			return (0);
		}
		i++;
	}
	return (1);
}

void			print_int(unsigned int number)
{
	if (number == 0)
		return ;
	print_int(number / 10);
	number = number % 10 + '0';
	write(1, &number, 1);
	return ;
}

int				validate_string(char *str)
{
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+')
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

unsigned int	simple_atoi(char *str)
{
	unsigned int		i;
	unsigned int		result;

	i = 0;
	result = 0;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result);
}

void			print_str(char *str)
{
	int		str_len;

	str_len = 0;
	while (*(str + str_len))
		str_len++;
	write(1, str, str_len);
}
