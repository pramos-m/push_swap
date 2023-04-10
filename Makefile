# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 14:18:46 by pramos-m          #+#    #+#              #
#    Updated: 2023/01/17 18:19:19 by pramos-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------RULES-----------------#

NAME = push_swap
BONUS = checker
MKFL = Makefile

#----------------COMANDS-----------------#

CFLAGS = -Wall -Werror -Wextra -W -O3 -Ofast
XFLAGS = -fsanitize=address -g3
RM = rm -rf
MD = mkdir -p
CP = cp -f

#----------------PATH-----------------#

SRC_DIR = src/
UTILS = utils/
INC_DIR = ./inc/
LIB_DIR = ./lib/
B_DIR	= bonus/

OBJ_DIR = ./.obj/

LIBFT_DIR = $(LIB_DIR)libft/

PRINT_DIR = $(LIB_DIR)printf/

LIBRARY = $(LIB_DIR)/*/*.a

#----------------PUSH_SWAP-----------------#

INCLUDE = -I$(INC_DIR) -I$(LIB_DIR) -I$(PRINT_DIR) -Ibonus/inc/

SRC_FLS = ft_check_input.c \
			ft_error.c \
			ft_init_stack.c \
			ft_big_sorting.c \
			ft_sort_short.c \
			ft_stack_operations.c \
			ft_stack_operations_ss.c \
			push_swap.c
			
UTL_FLS = push_swap_utils.c ft_sorting_utils.c

SRCS += $(addprefix $(SRC_DIR), $(SRC_FLS))
SRCS += $(addprefix $(UTILS), $(UTL_FLS))

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))
DEPS = $(OBJS:%.o=%.d)
#deps: pasamos los .o de los objetos a .d // las dependencias estan en la misma carpeta que los objetos
#------------------BONUS-------------------#

HDRS_BONUS	= $(B_DIR)$(INC_DIR)push_swap_bonus.h
INCLUDE_B	= -I $(B_DIR)$(INC_DIR)

SRC_B	= ft_check_input_bonus.c \
			ft_error_bonus.c \
			ft_init_stack_bonus.c \
			ft_stack_operations_bonus.c \
			ft_stack_operations_ss_bonus.c \
			push_swap_bonus.c
UTL_B = push_swap_utils_bonus.c

SRCS_BONUS += $(addprefix $(B_DIR), $(addprefix $(SRC_DIR), $(SRC_B)))
SRCS_BONUS += $(addprefix $(B_DIR), $(addprefix $(UTILS), $(UTL_B)))

OBJS_BONUS = $(addprefix $(OBJ_DIR), $(SRCS_BONUS:%.c=%.o))
DEPS_BONUS = $(OBJS_BONUS:%.o=%.d)

#------------------RULES-------------------#
# SINTAX DE REGLA
# antes de los ':' nombre de la regla. despues de los ':' las dependencias de la regla para ejecutarse. En el salto de linea lo que hará la regla al ejecutarse
$(OBJ_DIR)%.o: %.c $(LIBRARY)
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
#ejemplo practico 'gcc ft_check_input.c -I../inc -c -o patata'
# $@ == Nombre de la regla == $(OBJ_DIR)%.o
# $< == La primera dependencia de la regla == %.c
# cc es una variable de makefile que guarda el compilador de c (gcc). MMD crea los archivos de las dependencias 

all:
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) $(NAME)

$(NAME):: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME) 
	@echo "Push swap has been compiled!"

$(NAME)::
	@echo "nothing to be done for push swap"
#name siempre depende de objs, porque son los archivos
#els '::' s'utilitzen per a dir, si aixo ja s'ha fet, fes el seguent (que tingui els ::)
bonus:
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) $(BONUS)

$(BONUS)::$(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBRARY) -o $(BONUS) 

$(BONUS)::
	@echo "Nothing to be done for checker"

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) -rf $(OBJ_DIR)
	@echo "clean done"

fclean:
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) $(NAME) $(BONUS)
	@$(RM) -rf $(OBJ_DIR)
	@echo "fclean done"

re:
	@$(MAKE) fclean
	@$(MAKE) all

-include $(DEPS)
-include $(DEPS_BONUS)

.PHONY: all clean fclean re bonus
