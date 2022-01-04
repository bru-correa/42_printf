NAME			= libftprintf.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
ARFLAGS			= rcs

LIBFT_DIR		= ./libft
LIBFT			= $(LIBFT_DIR)/libft.a

SRC_DIR			= ./src
OBJ_DIR			= ./obj
INCLUDE			= ./include

SRCS			= $(wildcard $(SRC_DIR)/*.c)
OBJS			= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

all:			$(NAME)

bonus:			all

$(NAME):		$(LIBFT) $(OBJ_DIR) $(OBJS)
				cp $(LIBFT) $(NAME)
				ar $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -I $(LIBFT_DIR) -o $@

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR) bonus

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

clean:
				$(MAKE) -C $(LIBFT_DIR) clean
				rm -rf $(OBJ_DIR)

fclean:			clean
				$(MAKE) -C $(LIBFT_DIR) fclean
				rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft
