NAME = gnl

NAME_B = gnl_bonus

MAC = 

MAC_B = 

LIBFT = 

FLAGS 	= -Wall -Wextra
 
SRCS = gnl_recusif.c		\
	   main.c

SRCS_BONUS =	
 

CC 		= gcc
OBJ 	= ${SRCS:.c=.o}
OBJS 	= *.o
OBJ_B = ${SRCS_BONUS:.c=.o}
OBJS_B = *.o
 
.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}
 
all : 
	@make $(NAME)

$(NAME)	: $(OBJ) 
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
 
$(NAME_B) : $(OBJ_B)
	$(CC) $(FLAGS) $(OBJ_B) $(NAME_B)

clean : 
		@rm -rf $(OBJ)
		@rm -rf $(OBJ_B)
 
fclean : clean
		@rm -rf $(OBJS)
		@rm -rf $(OBJS_B)
		@rm -rf $(NAME)
		@rm -rf $(NAME_B)
 
relinux : fclean LINUX
 
re : fclean all
	
 
 
bonus : 
		@make ${NAME_B}
 
rebonus : fclean bonus
