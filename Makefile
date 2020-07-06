NAME		=	Cub3D

# COMPILER
CC			=	gcc

# FLAGS
CFLAGS		=	-Wall -Werror -Wextra

# HEADER
INC_DIR		=	./include
INC			=	-I $(INC_DIR)

# SOURCES
SRC_DIR		=	./src
SRC			=	main.c \
				error.c \
				init.c \
				init2.c \
				init_tex.c \
				init_map.c \
				init_map2.c \
				sprites.c \
				sprites2.c \
				raycast.c \
				draw.c \
				key.c \
				move.c \
				rotate.c \
				bitmap_file.c \
				exit_game.c \
				utils.c \

# BONUS
BNS_DIR		=	./bonus
BNS			=	main.c \
				error.c \
				line_parse.c \
				init.c \
				init2.c \
				init_tex.c \
				init_map.c \
				init_map2.c \
				sprites.c \
				sprites2.c \
				raycast.c \
				draw.c \
				key.c \
				move.c \
				rotate.c \
				bitmap_file.c \
				mini_map.c \
				lifebar.c \
				interact.c \
				timer.c \
				cursor.c \
				gun.c \
				exit_game.c \
				utils.c \
				utils2.c \


# OBJETS
OBJS_NAME	=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(SRC_DIR)/, $(OBJS_NAME))

# MINILIBX
MLX_DIR		=	/usr/local/include
# MLX_DIR		=	./minilibx_opengl
MLX_LNK_DIR	=	/usr/local/lib/
#MLX_LNK_DIR	=	 $(MLX_DIR)
MLX_INC		=	-I $(MLX_DIR)
MLX_LNK		=	-L $(MLX_LNK_DIR) -lmlx -framework OpenGL -framework AppKit

# LIBFT LIB
FT_DIR		=	./libft
FT_INC		=	-I $(FT_DIR)
FT_LNK		=	-L $(FT_DIR) -lft
LIBFT		=	$(addprefix $(FT_DIR), libft.a)

# OBJETS BNS
OBJS_NAME_B	=	$(BNS:.c=.o)
OBJS_BNS	=	$(addprefix $(BNS_DIR)/, $(OBJS_NAME_B))

# RULES
all			:	 $(NAME)

$(LIBFT)	:
				@echo "\nCompiling $(FT_DIR)..."
				@make -C $(FT_DIR)

$(NAME)		:	$(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) $(INC) $(FT_INC) $(MLX_INC) \
				$(addprefix $(SRC_DIR)/, $(SRC)) $(FT_LNK) $(MLX_LNK) -o $(NAME)

bonus		:	$(LIBFT) $(OBJS_BNS)
				$(CC) $(CFLAGS) $(INC) $(FT_INC) $(MLX_INC) \
				$(addprefix $(BNS_DIR)/, $(BNS)) $(FT_LNK) $(MLX_LNK) -o $(NAME)

clean		:
				@echo "\nCleaning Directories..."
				@rm -rf $(OBJS)
				@rm -rf $(OBJS_BNS)
				make clean -C $(FT_DIR)

fclean		:	clean
				rm -f $(NAME)
				make fclean -C $(FT_DIR)

re			:	fclean all
