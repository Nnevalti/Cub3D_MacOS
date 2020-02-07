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
				init.c \
				raycast.c \
				draw.c \
				key.c \
				move.c \
				mini_map.c \
				bitmap_file.c \
				exit_game.c \

# OBJETS
OBJS_NAME	=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(SRC_DIR)/, $(OBJS_NAME))

# MINILIBX LIB
# MLX_DIR		=	./minilibx
# MLX_DIR		=	./minilibx_opengl
MLX_DIR		=	/usr/local/include
MLX_LNK_DIR	=	/usr/local/lib/
MLX_INC		=	-I $(MLX_DIR)
# MLX_LNK		=	-L$(MLX_DIR) -lmlx
MLX_LNK		=	-L $(MLX_LNK_DIR) -lmlx -framework OpenGL -framework AppKit
# MLX			=	$(addprefix $(MLX_DIR)/, libmlx.dylib)

# LIBFT LIB
FT_DIR		=	$(addprefix $(SRC_DIR)/, libft)
FT_INC		=	-I $(FT_DIR)
FT_LNK		=	-L $(FT_DIR) -lft
LIBFT		=	$(addprefix $(FT_DIR), libft.a)

# RULES
all			:	$(LIBFT) $(NAME)

# $(MLX)		:
# 				@echo "\nCompiling $(MLX_DIR)..."
# 				@make -C $(MLX_DIR)

$(LIBFT)	:
				@echo "\nCompiling $(FT_DIR)..."
				@make -C $(FT_DIR)

$(NAME)		:	$(OBJS)
				$(CC) -fsanitize=address $(CFLAGS) $(INC) $(FT_INC) $(MLX_INC) $(addprefix $(SRC_DIR)/, $(SRC)) $(FT_LNK) $(MLX_LNK) -o $(NAME)

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
