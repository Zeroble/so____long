MAIN_OBJ =	./main.o \
			./src/map/check_map_error.o \
			./src/map/check_vailed_path.o \
			./src/map/map_parser.o \
			./src/map/set_map.o \
			./src/utils/graphic_utils.o \
			./src/utils/init_utils.o \
			./src/utils/perror_and_exit.o \
			./src/utils/print_nbr.o \
			./src/utils/print_walk.o \
			./src/utils/str_utils.o \

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long

all : ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c -Imlx $? -o $@

# %.o : %.c
# 	${CC} -c -Imlx $? -o $@

$(NAME) : ${MAIN_OBJ}
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $(NAME)

clean :
	rm -f ${MAIN_OBJ}

fclean : clean
	rm -f ${NAME}

re :
	make fclean
	make all
