cc=g++
exe=main
obj=main.o
$(exe):$(obj)
	$(cc) -o $(exe) $(obj)
main.o:main.cc
	$(cc) -c $<

clean:
	rm -rf %.o $(exe)