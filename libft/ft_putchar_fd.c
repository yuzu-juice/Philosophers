/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:39:55 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <string.h>

// int main() {
//     char filename[] = "testfile.txt";
//     char test_char = 'A';
//     char buffer[2] = {0};

//     int fd = open(filename, O_CREAT | O_RDWR, 0666);
//     if (fd == -1) {
//         perror("open");
//         return 1;
//     }

//     ft_putchar_fd(test_char, fd);

//     // ファイルの内容を確認するために読み取る
//     lseek(fd, 0, SEEK_SET); // ファイルポインタを先頭に移動
//     read(fd, buffer, 1); // 1バイト読み取る
//     buffer[1] = '\0'; // 終端文字を追加

//     // 結果を表示
//     printf("Written character: %c\n", buffer[0]);

//     close(fd);
//     remove(filename);

//     return 0;
// }