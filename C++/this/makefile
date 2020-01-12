cc=g++
exe=main
obj=main.o
$(exe):$(obj)
	$(cc) -g -o $(exe) $(obj)
main.o:main.cc
	$(cc) -g -c $<

clean:
	rm -rf %.o $(exe)