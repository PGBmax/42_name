/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coq_printf_tester.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:51:47 by mscheman          #+#    #+#             */
/*   Updated: 2024/10/16 18:21:20 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef enum e_color
{
	BLACK = 30,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
	RESET = 0
} t_color;

void	solo_test(char *test);
void	test_all();
void	test_chr();
void	test_str();
void	test_ptr();
void	test_dec();
void	test_int();
void	test_uns();
void	test_hex();
void	test_pct();
void	putclr(t_color clr);
void	stdout_clearlastline();

int main(int argc, char *argv[])
{
	if (argc == 1)
		test_all();
	else
		solo_test(argv[1]);
	return 0;
}

void	solo_test(char *test)
{
	for (size_t i = 0; test[i]; i++)
	{
		printf("\nTesting %%%c\n", test[i]);
		switch (test[i])
		{
		case 'c':
			test_chr();
			break;
		case 's':
			test_str();
			break;
		case 'p':
			test_ptr();
			break;
		case 'd':
			test_dec();
			break;
		case 'i':
			test_int();
			break;
		case 'u':
			test_uns();
			break;
		case 'x':
			test_hex();
			break;
		case '%':
			test_pct();
			break;
		default:
			printf("Missinput!");
			break;
		}
	}
}

void	test_all()
{
	printf("Now testing: %%c\n");
	test_chr();
	printf("\nFinished testing: %%c\n");

	printf("\nNow testing: %%s\n");
	test_str();
	printf("\nFinished testing: %%s\n");

	printf("\nNow testing: %%p\n");
	test_ptr();
	printf("\nFinished testing: %%p\n");

	printf("\nNow testing: %%d\n");
	test_dec();
	printf("\nFinished testing: %%d\n");

	printf("\nNow testing: %%i\n");
	test_int();
	printf("\nFinished testing: %%i\n");

	printf("\nNow testing: %%u\n");
	test_uns();
	printf("\nFinished testing: %%u\n");

	printf("\nNow testing: %%x and %%X\n");
	test_hex();
	printf("\nFinished testing: %%x and %%X\n");

	printf("\nNow testing: %%%%\n");
	test_pct();
	printf("\nFinished testing: %%%%\n");
}

void	test_chr()
{
	sleep(1);
	if (true) // test 1
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%c%c%c%c%c%c\n", 'p', 'r', 'i', 'n', 't', 'f') - 23;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%c%c%c%c%c%c\n", 'p', 'r', 'i', 'n', 't', 'f') - 23;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 2
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%c%c%c%c%c%c\n", 112, 114, 105, 110, 116, 102) - 23;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%c%c%c%c%c%c\n", 112, 114, 105, 110, 116, 102) - 23;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n\n", norm, user);
	}
	sleep(1);
	if (true) // test 3
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%c\n", INT_MAX) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%c\n", INT_MAX) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 4
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%c\n", INT_MIN) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%c\n", INT_MIN) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 5
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%c\n", NULL) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%c\n", NULL) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
}

void	test_str()
{
	sleep(1);
	if (true) // test 1
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%s\n", "Stop yapping!") - 23;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%s\n", "Stop yapping!") - 23;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 2
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%s%s%s%s\n", "Stop yapping!", "I can write", " whole sentences!", " dababy") - 23;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%s%s%s%s\n", "Stop yapping!", "I can write", " whole sentences!", " dababy") - 23;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 3
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%s\n", "") - 23;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%s\n", "") - 23;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 4
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%s %s\n", 0, NULL) - 23;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%s %s\n", 0, NULL) - 23;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 5
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%s ", "I will never stop yapping") - 22;
		ft_printf("\n");
		int	norm = printf("\033[1;33mExpected: \033[1;0m%s ", "I will never stop yapping") - 22;
		printf("\n");
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
}

void	test_ptr()
{
	sleep(1);
	if (true) // test 1
	{
		ft_printf("\n"); // only weird color pattenrs
		void *ptr = 431136;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%p\n", ptr) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%p\n", ptr) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 2
	{
		ft_printf("\n"); // only weird color pattenrs
		void *ptr = LLONG_MIN;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%p\n", ptr) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%p\n", ptr) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 3
	{
		ft_printf("\n"); // only weird color pattenrs
		void *ptr = INT_MIN;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%p\n", ptr) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%p\n", ptr) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 4
	{
		ft_printf("\n"); // only weird color pattenrs
		void *ptr = 270441;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%p\n", ptr) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%p\n", ptr) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 5
	{
		ft_printf("\n"); // only weird color pattenrs
		void *ptr = 18446744073709551615;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%p\n", ptr) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%p\n", ptr) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 6
	{
		ft_printf("\n"); // only weird color pattenrs
		void *ptr = 0;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%p\n", ptr) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%p\n", ptr) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
}

void	test_dec()
{
	sleep(1);
	if (true) // test 1
	{
		ft_printf("\n"); // only weird color pattenrs
		int	test = 69420;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%d\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%d\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 2
	{
		ft_printf("\n"); // only weird color pattenrs
		int	test = -69420;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%d\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%d\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 3
	{
		ft_printf("\n"); // only weird color pattenrs
		int	test = INT_MAX;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%d\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%d\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 4
	{
		ft_printf("\n"); // only weird color pattenrs
		int	test = INT_MIN;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%d\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%d\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 5
	{
		ft_printf("\n"); // only weird color pattenrs
		int	test = 0;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%d\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%d\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 6
	{
		ft_printf("\n"); // only weird color pattenrs
		int	test = -0;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%d\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%d\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 7
	{
		ft_printf("\n"); // only weird color pattenrs
		int	test = 'a'; // 97
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%d\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%d\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 8
	{
		ft_printf("\n"); // only weird color pattenrs
		long	test = LONG_MAX;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%d\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%d\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
}

void	test_int()
{
	sleep(1);
	if (true) // test 1
	{
		ft_printf("\n"); // only weird color pattenrs
		int	test = 69420;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%i\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%i\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 2
	{
		ft_printf("\n"); // only weird color pattenrs
		int	test = -69420;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%i\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%i\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 3
	{
		ft_printf("\n"); // only weird color pattenrs
		int	test = INT_MAX;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%i\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%i\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 4
	{
		ft_printf("\n"); // only weird color pattenrs
		int	test = INT_MIN;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%i\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%i\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 5
	{
		ft_printf("\n"); // only weird color pattenrs
		int	test = 0;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%i\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%i\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 6
	{
		ft_printf("\n"); // only weird color pattenrs
		int	test = -0;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%i\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%i\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 7
	{
		ft_printf("\n"); // only weird color pattenrs
		int	test = 'a'; // 97
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%i\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%i\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 8
	{
		ft_printf("\n"); // only weird color pattenrs
		long	test = LONG_MAX;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%i\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%i\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
}

void	test_uns()
{
	sleep(1);
	if (true) // test 1
	{
		ft_printf("\n"); // only weird color pattenrs
		unsigned int	test = 69420;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%u\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%u\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 2
	{
		ft_printf("\n"); // only weird color pattenrs
		unsigned int	test = -69420;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%u\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%u\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 3
	{
		ft_printf("\n"); // only weird color pattenrs
		unsigned int	test = UINT_MAX;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%u\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%u\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 4
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%u\n", INT_MIN) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%u\n", INT_MIN) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 5
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%u\n", LONG_MIN) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%u\n", LONG_MIN) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		igf (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 6
	{
		ft_printf("\n"); // only weird color pattenrs
		unsigned int	test = 0;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%u\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%u\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 7
	{
		ft_printf("\n"); // only weird color pattenrs
		unsigned int	test = -0;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%u\n", test) - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%u\n", test) - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
}

void	test_hex()
{
	sleep(1);
	if (true) // test 1
	{
		ft_printf("\n"); // only weird color pattenrs
		unsigned int test = 431136;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%x %X\n", test, test) - 25;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%x %X\n", test, test) - 25;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 2
	{
		ft_printf("\n"); // only weird color pattenrs
		unsigned int test = LLONG_MIN;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%x %X\n", test, test) - 25;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%x %X\n", test, test) - 25;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 3
	{
		ft_printf("\n"); // only weird color pattenrs
		unsigned int test = INT_MIN;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%x %X\n", test, test) - 25;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%x %X\n", test, test) - 25;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 4
	{
		ft_printf("\n"); // only weird color pattenrs
		unsigned int test = 270441;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%x %X\n", test, test) - 25;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%x %X\n", test, test) - 25;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 5
	{
		ft_printf("\n"); // only weird color pattenrs
		unsigned int test = 18446744073709551615;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%x %X\n", test, test) - 25;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%x %X\n", test, test) - 25;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 6
	{
		ft_printf("\n"); // only weird color pattenrs
		unsigned int test = 0;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%x %X\n", test, test) - 25;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%x %X\n", test, test) - 25;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 7
	{
		ft_printf("\n"); // only weird color pattenrs
		unsigned int test = 3216523;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%x %X\n", test, test) - 25;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%x %X\n", test, test) - 25;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 8
	{
		ft_printf("\n"); // only weird color pattenrs
		unsigned int test = -465318;
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%x %X\n", test, test) - 25;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%x %X\n", test, test) - 25;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
}

void	test_pct()
{
	sleep(1);
	if (true) // test 1
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%%\n") - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%%\n") - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 2
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m100%% des morts sont decedes alors que 0%% des vivants sont morts\n") - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m100%% des morts sont decedes alors que 0%% des vivants sont morts\n") - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
	sleep(1);
	if (true) // test 3
	{
		ft_printf("\n"); // only weird color pattenrs
		int	user = ft_printf("\033[1;36mUser:     \033[1;0m%%%%%%%%%%%%%%\n") - 24;
		int	norm = printf("\033[1;33mExpected: \033[1;0m%%%%%%%%%%%%%%\n") - 24;
		if (user > norm)
		{
			putclr(RED);
			printf("Too many characters!\n");
			putclr(RESET);
		}
		if (user < norm)
		{
			putclr(RED);
			printf("Not enough characters!\n");
			putclr(RESET);
		}
		printf("Diff:     \033[1;33m%d\033[1;0m vs \033[1;36m%d\033[1;0m\n", norm, user);
	}
}

void	stdout_clearlastline()
{
	printf("\33[2K\r");
}

void	putclr(t_color clr)
{
	switch (clr)
	{
	case 30: // black
		printf("\033[1;30m");
		break;
	case 31: // red
		printf("\033[1;31m");
		break;
	case 32: // green
		printf("\033[1;32m");
		break;
	case 33: // yellow
		printf("\033[1;33m");
		break;
	case 34: // blue
		printf("\033[1;34m");
		break;
	case 35: // magenta
		printf("\033[1;35m");
		break;
	case 36: // cyan
		printf("\033[1;36m");
		break;
	case 37: // white
		printf("\033[1;37m");
		break;
	case 0: // reset
		printf("\033[1;0m");
		break;
	default: // error
		printf("Missinput");
		break;
	}
}
