/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:39:55 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}

// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <string.h>

// int main() {
//     char filename[] = "testfile.txt";
//     int num = 123;
//     char *buffer;

// 	buffer = malloc(sizeof(char) * 4);
//     int fd = open(filename, O_CREAT | O_RDWR, 0666);
//     if (fd == -1) {
//         perror("open");
//         return 1;
//     }

//     ft_putnbr_fd(num, fd);

//     // ファイルの内容を確認するために読み取る
//     lseek(fd, 0, SEEK_SET); // ファイルポインタを先頭に移動
//     read(fd, buffer, 3);
//     buffer[3] = '\0'; // 終端文字を追加

//     // 結果を表示
//     printf("Written number: %s\n", buffer);

//     close(fd);
//     remove(filename);

//     return 0;
// }