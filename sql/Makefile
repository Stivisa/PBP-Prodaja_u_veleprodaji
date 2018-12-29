DIR	= sql
PROGS	= 1 2
CFLAGS	= -g -Wall `mysql_config --cflags --libs`

.PHONY: all create insert beauty dist progs

progs: $(PROGS)

all: create insert compile1 compile2

create:
	mysql -u nikola -pnikola -D mysql <veleprodaja.sql

insert:
	mysql -u nikola -pnikola -D mysql <insert.sql
	
compile1:

	gcc 1.c -o 1 $(CFLAGS)
	
compile2:

	gcc 2.c -o 2 $(CFLAGS)
	
beauty:
	-indent $(PROGS).c

clean:
	-rm -f *~ $(PROGS)
	
dist: beauty clean
	-tar -czv -C .. -f ../$(DIR).tar.gz $(DIR)
	
