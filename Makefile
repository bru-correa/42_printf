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

T_DIR			= ./tests
UNITY			= $(T_DIR)/Unity
T_BIN			= $(T_DIR)/bin
T_SRC			= $(T_DIR)/src
T_OBJ			= $(T_DIR)/obj
T_INCLUDE		= $(T_DIR)/include
T_SRCS			= $(wildcard $(T_SRC)/*.c)
T_OBJS			= $(patsubst $(T_SRC)%.c, $(T_OBJ)%.o, $(T_SRCS))
T_EXE			= $(T_BIN)/tests

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

$(T_OBJ)/%.o:	$(T_SRC)/%.c
				$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -I $(UNITY) \
				-I $(LIBFT_DIR) -I $(T_INCLUDE) -o $@

# test_%:			$(TEST_SRC)/test_%.c
# 				$(CC) $(CFLAGS) -g $< $(NAME) $(TESTS_DIR)/unity.c \
# 				-I $(UNITY) -I $(INCLUDE) -o $(TESTS_BIN)/$@

tests:			$(T_OBJS)
				$(CC) $(CFLAGS) -g $< $(NAME) -I $(INCLUDE) -I $(LIBFT_DIR) \
				-I $(T_INCLUDE) -o $(T_EXE)

run:			all tests
				./$(T_EXE)

.PHONY:			all clean fclean re libft tests run
