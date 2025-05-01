/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:39:55 by takitaga          #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <string.h>

// int main() {
//     char filename[] = "testfile.txt";
//     char test_str[] = "ABC";
//     char *buffer;

// 	buffer = malloc(sizeof(char) * (ft_strlen(test_str) + 1));
//     int fd = open(filename, O_CREAT | O_RDWR, 0666);
//     if (fd == -1) {
//         perror("open");
//         return 1;
//     }

//     ft_putendl_fd(test_str, fd);

//     // ファイルの内容を確認するために読み取る
//     lseek(fd, 0, SEEK_SET); // ファイルポインタを先頭に移動
//     read(fd, buffer, ft_strlen(test_str));
//     buffer[ft_strlen(test_str)] = '\0'; // 終端文字を追加

//     // 結果を表示
//     printf("Written string: %s\n", buffer);

//     close(fd);
//     remove(filename);

//     return 0;
// }