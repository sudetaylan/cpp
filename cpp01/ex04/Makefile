NAME		= sed

SRCS		= 	Sed.cpp\
				main.cpp

OBJS		= $(SRCS:.cpp=.o)

CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.replace

re: fclean all

.PHONY: all clean fclean re