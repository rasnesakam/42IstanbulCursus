/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg-parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:41:25 by emakas            #+#    #+#             */
/*   Updated: 2022/08/04 15:58:53 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGPARSER_H
#define ARGPARSER_H
#include "../../libft/libft.h"

int		count_words(char *c);
int		count_args(int ac, char **args);
char	**collect_args(int ac, char **args);

# endif