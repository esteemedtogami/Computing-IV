C=g++ -g -Wall --std=c++98 -Werror
E=.cpp
O=test.o LFSR.o
P=ps2a
BOOST= -lboost_unit_test_framework
#SFML= -lsfml-graphics -lsfml-window -lsfml-system
all: $(P)
$(P):$(O)
	$(C) -o $(P) $(O) $(BOOST)

$(E).o:
	$(C) -c $<  -o $@

clean:
	rm $(O) $(P)
