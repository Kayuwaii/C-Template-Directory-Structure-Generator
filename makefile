mkcodedir:
	gcc -c helpers/filesystemHelpers.c -o helpers/filesystemHelpers
	gcc -c mkCodeDir.c -o mkCodeDir.o
	gcc -g mkCodeDir.o helpers/filesystemHelpers -o mkcodedir
	rm -f helpers/filesystemHelpers
	rm -f mkCodeDir.o

mkcodedir-publish:
	gcc -c helpers/filesystemHelpers.c -o helpers/filesystemHelpers
	gcc -c mkCodeDir.c -o mkCodeDir.o
	gcc -zexecstack -fno-stack-protector -fno-pic  -no-pie  mkCodeDir.o helpers/filesystemHelpers -o mkcodedir
	sudo mv mkcodedir /usr/bin/mkcodedir
	rm -f helpers/filesystemHelpers
	rm -f mkCodeDir.o
