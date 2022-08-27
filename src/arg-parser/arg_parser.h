/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg-parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:41:25 by emakas            #+#    #+#             */
/*   Updated: 2022/08/27 17:35:08 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_PARSER_H
#define ARG_PARSER_H
int		count_words(char *c);
int		count_args(int ac, char **args);
char	**collect_args(int ac, char **args);

# endif