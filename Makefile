PROJ = TTT

ifeq ($(shell uname), Darwin)
	APP = $(PROJ)/$(PROJ).app/Contents/MacOS/$(PROJ)
else ifeq ($(shell uname), Linux)
	APP = $(PROJ)/$(PROJ)
endif


all: clean app play

play:
	./$(APP)

app:
	cd $(PROJ)
	sh run.sh

clean:
	rm -rf build*
	-$(MAKE) clean --directory=$(PROJ)
	-$(MAKE) distclean --directory=$(PROJ)

qt:
	sh ~/Projects/s21_INSTASCRYPTS/src/instaqt.sh