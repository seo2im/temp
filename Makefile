TARGET = minishell
HEADER = -I ./Header/
SRC = ./main.c	\
		./srcs/Redirection/*.c	\
		./srcs/builtin/*/*.c \
		./srcs/Parser/*.c \
		./srcs/Shell/*.c \
		./srcs/Shell/multi/*.c \
		./srcs/external/Echo/echo.c \
		./srcs/external/Env/env.c \
		./srcs/external/Pwd/pwd.c \
		./srcs/library/Envlib/*.c \
		./srcs/library/Lib/*.c \
		./srcs/gnl/*.c
FLAG = -Wall -Werror -Wextra

all : $(TARGET)

$(TARGET) : $(SRC)
	gcc -o $(TARGET) $(SRC) $(HEADER)

fclean :
	rm -rf $(TARGET)

re : fclean all