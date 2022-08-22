NAME = philosophers

DIR_SRC = src
DIR_BIN = bin/

DIRS = /\
		/arg-converter/ \
		/arg-parser/ \
		/arg-verifier/

SRC_DIRS = $(addprefix $(DIR_SRC), $(DIRS))			

SRC					= $(wildcard $(addsuffix *.c, $(SRC_DIRS)))


info:
	@echo $(SRC)


$(SRC:.c=.o): 
	@echo sa