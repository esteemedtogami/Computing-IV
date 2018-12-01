C=g++ -g -Wall --std=c++98 -Werror
E=.cpp
O=original.o maine.o
S=sierpinski.o main.o
P=sierpinski
Q=original
SFML= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
all: $(P) $(Q)
$(P):$(S)
	$(C) -o $(P) $(S) $(SFML)

$(Q):$(O)
	$(C) -o $(Q) $(O) $(SFML)

$(E).o:
	$(C) -c $<  -o $@

clean:
	rm $(O) $(P) $(Q) $(S)

.PHONY: clean
