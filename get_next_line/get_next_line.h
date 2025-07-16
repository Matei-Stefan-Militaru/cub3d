/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:55:47 by pmorello          #+#    #+#             */
/*   Updated: 2025/07/16 11:24:13 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// llibrerias
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

//funcins
char	*get_next_line(int fd);
char	*ft_read_fd(int fd, char *buffer);
char	*ft_read_line(char *buffer);
char	*ft_new_line(char *buffer);
char    *gnl_strchr(char *buffer, int c);
char	*gnl_strjoin(char *buffer, char *new_buffer);

#endif
