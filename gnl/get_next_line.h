/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:06:57 by emakas            #+#    #+#             */
/*   Updated: 2022/02/18 17:34:51 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	ft_merge(char **s1, char *s2);
char	*ft_strpos(char *str, int c);
void	ft_setnull(char *s, int after);
int		ft_len(char *s);
char	*get_next_line(int fd);
#endif