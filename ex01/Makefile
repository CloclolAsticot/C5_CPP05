#########################################
#				VARIABLES				#
#########################################

NAME = bureaucrat

# Compilation
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
DEPFLAGS = -MMD -MP

# Directories
D_OBJS 			= objs

# Source Files (only .cpp files)
FILES 	= 	main.cpp		\
			Bureaucrat.cpp  \
			Form.cpp


OBJS 		= 	$(patsubst %.cpp,$(D_OBJS)/%.o,$(FILES))
DEPS		=	$(OBJS:.o=.d)

#########################################
#				   RULES				#
#########################################

.PHONY : all
all: $(D_OBJS) $(NAME)

$(D_OBJS)/%.o: %.cpp Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(D_OBJS):
	mkdir -p $(D_OBJS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

-include $(DEPS)

.PHONY : clean
clean:
	@echo "clean objs from /$(NAME)"
	@rm -rf $(D_OBJS)

.PHONY : fclean
fclean: 
	@$(MAKE) --no-print-directory clean
	@echo "clean $(NAME) from /$(NAME)"
	@rm -f $(NAME)

.PHONY : re
re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all