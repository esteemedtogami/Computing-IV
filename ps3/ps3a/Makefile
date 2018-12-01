C=g++ -g -Wall --std=c++98 -Werror
E=.cpp
O=main.o Body.o
P=NBody
SFML= -lsfml-graphics -lsfml-window -lsfml-system
all: $(P)
$(P):$(O)
	$(C) -o $(P) $(O) $(SFML)

$(E).o:
	$(C) -c $<  -o $@

clean:
	rm $(O) $(P)
