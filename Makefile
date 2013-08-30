CXX		=	g++-4.8
CXXFLAGS	=	-W -Wall -Werror -Wextra -std=c++11
NAME		=	id_invader
SRC		=	main.cpp	\
			scene.cpp	\
			window.cpp	\
			intro.cpp	\
			surface.cpp	\
			timer.cpp	\
			game.cpp	\
			ship.cpp	\
			ennemy.cpp
OBJ		=	$(SRC:.cpp=.o)
LDFLAGS		=	-lSDL -lSDL_image -lSDL_ttf -g3

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

distclean:	clean
		rm -f $(NAME)

rebuild:	distclean all

.PHONY: all clean distclean rebuild

