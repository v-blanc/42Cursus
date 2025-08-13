/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:45:46 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/18 14:35:59 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_FUNCTIONS_H
# define GC_FUNCTIONS_H

# include "../libft/libft.h"
# include "print.h"
# include "struct.h"
# include <errno.h>
# include <stdlib.h>
# include <string.h>

void	*gc_malloc(size_t size, t_gc **head);
void	**gc_malloc_array(size_t size, t_gc **head);
void	*gc_malloc_perm(size_t size, t_gc **head);
void	**gc_malloc_array_perm(size_t size, t_gc **head);
void	gc_free(void *mem, t_gc **head);
void	gc_free_array(char **array, t_gc **head);
void	gc_free_all(t_gc **head);
void	gc_free_all_perm(t_gc *head);
char	*gc_strjoin(char *s1, char *s2, t_gc **head);
char	*gc_strjoin_perm(char *s1, char *s2, t_gc **head);
char	*gc_strdup(const char *s, t_gc **head);
char	*gc_strdup_perm(const char *s, t_gc **head);
char	*gc_substr(char const *s, unsigned int start, size_t len, t_gc **head);
char	**gc_split(char const *s, char c, t_gc **head);
char	*gc_itoa(int n, t_gc **head);
char	*gc_strndup(const char *s, size_t n, t_gc **head);
int		gc_setenv(char *name, char *value, t_gc **head);

#endif