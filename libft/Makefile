# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyeo <responsible@kakao.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 19:23:16 by seyeo             #+#    #+#              #
#    Updated: 2022/02/27 14:13:48 by seyeo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR	= ar rcs

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_addchr.c ft_isdigit.c ft_isprint.c ft_memset.c ft_printf_itoa.c \
		ft_strchr.c ft_strdup.c ft_strdupn.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_memcpy.c

OBJS = $(SRCS:.c=.o)

.c.o :
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
		
$(NAME) : $(OBJS)
		$(AR) $@ $^

all : $(NAME)

clean :
		$(RM) $(OBJS)

fclean :	clean
			$(RM) $(NAME)

re :	fclean all

.PHONY : all clean fclean re