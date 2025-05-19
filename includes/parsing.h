/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanc <vblanc@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:08:12 by vblanc            #+#    #+#             */
/*   Updated: 2025/05/19 15:42:51 by vblanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "utils.h"
# include "variables.h"
# include <ctype.h>
# include <dirent.h>

// tokens_utils

int				is_operator_char(char c);
t_token_type	get_op_type(const char *s, int *len);
t_token			*new_token(t_token_type type, char quote_type,
					const char *value, t_gc **head);
void			token_add_back(t_token **tokens, t_token *new_token);

// tokenizer

int				tokenizer(t_token **tokens, const char *s, t_context **ctx);
int				heredoc_tokenizer(t_token **tks, const char *s, t_gc **gc);
char			*parse_quoted_word(const char *s, int *i, t_gc **head);
int				catch_syntax_error(t_token *t, t_context **ctx);

// expander

int				is_valid_var_char(char c, int pos);
int				get_expand_len(char *word, t_context *ctx);
int				expand_tilde(char **word, t_gc **head);
int				expand_one_token(char **w, int len_w, t_context *ctx);
int				expander(t_token **tokens, t_context *ctx);
int				merge_tokens(t_token **tokens, t_gc **head);

// wildcard

bool			is_file_needed(t_token *tok, char *file);
int				get_wildcard(char ***files, t_gc **head);
int				wildcard(t_token **tokens, t_gc **head);

// parser_utils

int				is_redirection(t_token_type type);
int				count_cmd_args(t_token *tok);
int				count_cmd_redir(t_token *tok);
int				get_fd_source(t_token_type type);

// parser

t_ast			*parse_primary(t_token **tokens, t_context **ctx);
t_ast			*parse_pipeline(t_token **tokens, t_context **ctx);
t_ast			*parse_command(t_token **tok, t_context **ctx);
t_ast			*parser(t_token **tokens, t_context **ctx);

// main parsing
int				parsing(char *input, t_ast **ast, t_context **context);

void			print_ast(t_ast *node, int depth);

#endif