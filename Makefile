# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyeo <responsible@kakao.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 15:10:15 by seyeo             #+#    #+#              #
#    Updated: 2022/03/21 13:16:54 by seyeo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_D = ./libft
LIBFT = $(LIBFT_D)/libft.a

INCLUDE_D = ./include

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I$(INCLUDE_D)  -I$(LIBFT_D)
AR	= ar -rcs

SRCS_D = ./srcs
RM = rm -f

SRCS = $(SRCS_D)/ft_conversion_c.c \
		$(SRCS_D)/ft_conversion_digit.c \
		$(SRCS_D)/ft_conversion_id.c \
		$(SRCS_D)/ft_conversion_p.c \
		$(SRCS_D)/ft_conversion_percent.c \
		$(SRCS_D)/ft_conversion_s.c \
		$(SRCS_D)/ft_convert.c \
		$(SRCS_D)/ft_init.c \
		$(SRCS_D)/ft_pad.c \
		$(SRCS_D)/ft_parse.c \
		$(SRCS_D)/ft_prefix.c \
		$(SRCS_D)/ft_printf.c \
		$(SRCS_D)/ft_syntax.c
		
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS) 
		$(AR) $(NAME) $(OBJS)
.c.o :
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)
		
$(LIBFT) :
			make -C $(LIBFT_D)
			cp $(LIBFT) $(NAME)


bonus : all

clean :
		make clean -C $(LIBFT_D)
		$(RM) $(OBJS)

fclean :	clean
			make fclean -C $(LIBFT_D)
			$(RM) $(NAME)

re :	fclean all

rebonus : fclean bonus

.PHONY : all clean fclean re bonus rebonus