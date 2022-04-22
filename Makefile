SRCS		= main2.cpp

OBJS			= $(SRCS:.cpp=.o)

DEPS			= $(SRCS:.cpp=.d)

NAME			= containers
NAME_STD		= containers_std
CC				= clang++
CFLAGS			= --std=c++98 -Wall -Wextra -Werror

all:			$(NAME)

%.o: 			%.cpp
				$(CC) $(CFLAGS) -MM -MG -MT $@ $< -o $(@:%.o=%.d)
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:			
				$(RM) $(OBJS)
				$(RM) $(DEPS)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(NAME_STD)

std:
				$(CC) $(CFLAGS) -D STD -c $(SRCS) -o $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME_STD) $(OBJS)

re:			fclean all

.PHONY:		re fclean clean all std test

-include $(DEPS)


#clang++ -D STD main.cpp -o main