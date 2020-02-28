NAME		=	Cub3D

# COMPILER
CC			=	gcc

# FLAGS
$(CFLAGS)	:
				-Wall -Werror -Wextra

# HEADER
INC_DIR		=	./include
INC_NAME	=	Cub3D.h \
INC			=	-I $(addprefix $(INC_DIR)/, $INC_NAME)
# SOURCES
SRC_DIR		=	./src
SRC			=	main.c \
				error.c \
				init.c \
				init_tex.c \
				init_map.c \
				raycast.c \
				draw.c \
				key.c \
				move.c \
				mini_map.c \
				bitmap_file.c \
				exit_game.c \
				utils.c \

# OBJETS
OBJS_NAME	=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(SRC_DIR)/, $(OBJS_NAME))

# MINILIBX
MLX_DIR		=	/usr/local/include
MLX_LNK_DIR	=	/usr/local/lib/
MLX_INC		=	-I $(MLX_DIR)
MLX_LNK		=	-L $(MLX_LNK_DIR) -lmlx -framework OpenGL -framework AppKit

# LIBFT LIB
FT_DIR		=	$(addprefix $(SRC_DIR)/, libft)
FT_INC		=	-I $(FT_DIR)
FT_LNK		=	-L $(FT_DIR) -lft
LIBFT		=	$(addprefix $(FT_DIR), libft.a)

# RULES
all			:	$(LIBFT) $(NAME)

$(LIBFT)	:
				@echo "\nCompiling $(FT_DIR)..."
				@make -C $(FT_DIR)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(INC) $(FT_INC) $(MLX_INC) $(addprefix $(SRC_DIR)/, $(SRC)) $(FT_LNK) $(MLX_LNK) -o $(NAME)

				# $(CC) -fsanitize=address $(CFLAGS) $(INC) $(FT_INC) $(MLX_INC) $(addprefix $(SRC_DIR)/, $(SRC)) $(FT_LNK) $(MLX_LNK) -o $(NAME)

clean		:
				@rm -rf $(OBJS)
				make clean -C $(FT_DIR)

fclean		:	clean
				@echo "\nCleaning Directories..."
				rm -f $(NAME)
				rm -f libmlx.dylib
				make fclean -C $(FT_DIR)
				make clean -C $(MLX_DIR)

re			:	fclean all
