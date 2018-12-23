DIR	= sql
PROGS	= 1 2
CFLAGS	= -g -Wall `mysql_config --cflags --libs`

.PHONY: all create insert beauty dist progs

progs: $(PROGS)

all: create insert $(PROGS)

create:
	sudo mysql -u root -proot -D mysql <veleprodaja.sql

insert:
	sudo mysql -u root -proot -D mysql <insert.sql

beauty:
	-indent $(PROGS).c

clean:
	-rm -f *~ $(PROGS)
	
dist: beauty clean
	-tar -czv -C .. -f ../$(DIR).tar.gz $(DIR)
	
