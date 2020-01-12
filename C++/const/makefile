# cc=g++       #指定编译器
# exe=const    #目标文件名
# obj=const.o  
# $(exe):$(obj)
# 	$(cc) -o $(exe) $(obj)
# const.o:const.cc
# 	$(cc) -c $<

# cc=g++       #指定编译器
# exe=file    #目标文件名
# obj=file1.o file2.o
# $(exe):$(obj)
# 	$(cc) -o $(exe) $(obj)
# file1.o:file1.cc
# 	$(cc) -c $<
# file2.o:file2.cc
# 	$(cc) -c $<

cc=g++       #指定编译器
exe=main    #目标文件名
obj=main.o apple.o
$(exe):$(obj)
	$(cc) -o $(exe) $(obj)
main.o:main.cc
	$(cc) -c $<
apple.o:apple.cc
	$(cc) -c $<

clean:
	rm -rf *.o $(exe)
