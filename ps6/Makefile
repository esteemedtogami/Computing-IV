C=g++ -g -Wall --std=c++98 -Werror
E=.cpp
O= MarkovModel.o TextGenerator.o
P=TextGenerator
BOOST= -lboost_unit_test_framework
all: $(P)
$(P):$(O)
	$(C) -o $(P) $(O) $(BOOST)

$(E).o:
	$(C) -c $<  -o $@

clean:
	rm $(O) $(P)
