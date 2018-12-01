C=g++ -g -Wall --std=c++98 -Werror
E=.cpp
O=GuitarHero.o RingBuffer.o GuitarString.o
P=GuitarHero
SFML= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
all: $(P)
$(P):$(O)
	$(C) -o $(P) $(O) $(SFML)

$(E).o:
	$(C) -c $<  -o $@

clean:
	rm $(O) $(P)
