
DIRS = ex00 ex01 ex02 ex03

$(DIRS)%:
	make -C $@ all

all: $(DIRS)



.PHONY: all re clean fclean