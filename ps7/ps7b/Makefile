C=g++ -g -Wall --std=c++98 -Werror
E=.cpp
O=main.o
P=ps7b
BOOST= -lboost_regex -lboost_date_time
all: $(P)
$(P):$(O)
	$(C) -o $(P) $(O) $(BOOST)

$(E).o:
	$(C) -c $<  -o $@

clean:
	rm $(O) $(P)
