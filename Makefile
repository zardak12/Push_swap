NAME = libpushswap.a
PUSH_SWAP_NAME = push_swap
CHECKER_NAME = checker

CC = gcc
FLAGS = -Wall -Werror -Wextra
HEADER_DIRECTORY = ./includes/
LIBFT = ./Libft/
PRINTF = ./Printf/
GET_NEXT_LINE = ./Get_next_line/
GET_NEXT_LINE_H = $(HEADER_DIRECTORY)get_next_line.h
LIBFT_H = $(HEADER_DIRECTORY)libft.h
PRINTF_H= $(HEADER_DIRECTORY)ft_printf.h

FT_COMPILED =	ft_putchar.o \
				ft_putstr.o \
				ft_strlen.o \
				ft_strcat.o \
				ft_strncat.o \
				ft_strlcat.o \
				ft_strcpy.o \
				ft_strncpy.o \
				ft_strdup.o \
				ft_strcmp.o \
				ft_strncmp.o \
				ft_strstr.o \
				ft_strnstr.o \
				ft_strchr.o \
				ft_strrchr.o \
				ft_isalpha.o \
				ft_isdigit.o \
				ft_isalnum.o \
				ft_isprint.o \
				ft_isascii.o \
				ft_tolower.o \
				ft_toupper.o \
				ft_bzero.o \
				ft_memset.o \
				ft_memchr.o \
				ft_memcmp.o \
				ft_memcpy.o \
				ft_memccpy.o \
				ft_memmove.o \
				ft_atoi.o \
				ft_memalloc.o \
				ft_memdel.o \
				ft_strnew.o \
				ft_strdel.o \
				ft_strclr.o \
				ft_striter.o \
				ft_striteri.o \
				ft_strmap.o \
				ft_strmapi.o \
				ft_strequ.o \
				ft_strnequ.o \
				ft_strsub.o \
				ft_strjoin.o \
				ft_strtrim.o \
				ft_strsplit.o \
				ft_itoa.o \
				ft_putendl.o \
				ft_putnbr.o \
				ft_putchar_fd.o \
				ft_putstr_fd.o \
				ft_putendl_fd.o \
				ft_putnbr_fd.o \
				ft_lstnew.o \
				ft_lstdelone.o \
				ft_lstdel.o \
				ft_lstadd.o \
				ft_lstiter.o \
				ft_lstmap.o \
				ft_strrev.o \
				ft_ltoa.o

PRINTF_COMPILED = free_conv.o \
				  ft_printf.o \
				  init_conv.o \
				  number_conv.o \
				  parser.o \
				  print.o \
				  print_blank.o \
				  print_conversion.o \
				  string_conv.o \
				  misc.o \
				  print_num.o \
				  float.o \
				  error.o \
				  float_2.o \

GET_COMPILED = get_next_line.o \

PUSHSWAP = push_swap.c

ALL_COMPILE =	validation.c\
				mix.c\
				additional.c\
				sort.c\
				find.c\
				add_ch.c\
				mix2.c\
				additional2.c\
				sort2.c\
				sort3.c

CHECKER    =  checker.c\

COMPILED = $(FT_COMPILED) $(PRINTF_COMPILED) $(GET_COMPILED)

.PHONY: re fclean clean

all : $(PUSH_SWAP_NAME) $(CHECKER_NAME)


$(PUSH_SWAP_NAME):$(COMPILED)
	ar rc $(NAME) $(COMPILED)
	ranlib $(NAME)
	$(CC) -g -o push_swap $(FLAGS) $(PUSHSWAP) $(ALL_COMPILE) $(NAME) -I $(HEADER_DIRECTORY)

$(CHECKER_NAME):$(COMPILED)
	ar rc $(NAME) $(COMPILED)
	ranlib $(NAME)
	$(CC) -g -o checker $(FLAGS) $(CHECKER) $(ALL_COMPILE) $(NAME) -I $(HEADER_DIRECTORY)


$(FT_COMPILED): %.o:$(LIBFT)%.c $(LIBFT_H)
	$(CC) -c $(FLAGS) -I $(HEADER_DIRECTORY) $< -o $@

$(PRINTF_COMPILED) : %.o:$(PRINTF)%.c $(PRINTF_H)
	$(CC) -c $(FLAGS) -I $(HEADER_DIRECTORY) $< -o $@

$(GET_COMPILED): %.o:$(GET_NEXT_LINE)%.c $(GET_NEXT_LINE_H)
	$(CC) -c $(FLAGS) -I $(HEADER_DIRECTORY) $< -o $@

clean:
	rm -f $(COMPILED)

fclean: clean
	rm -f $(PUSH_SWAP_NAME) $(CHECKER_NAME) $(NAME)

re: fclean all

