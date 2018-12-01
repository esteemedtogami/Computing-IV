C=g++ -g -Wall --std=c++98 -Werror
E=.cpp
O=PhotoMagic.o LFSR.o
P=PhotoMagic
BOOST= -lboost_unit_test_framework
SFML= -lsfml-graphics -lsfml-window -lsfml-system
all: $(P)
$(P):$(O)
	$(C) -o $(P) $(O) $(BOOST) $(SFML)

$(E).o:
	$(C) -c $<  -o $@

clean:
	rm $(O) $(P)
