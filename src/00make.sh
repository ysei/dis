#!/bin/sh

mv -v Makefile "Makefile_-_orig_-_`date`"
cp -v ports/Makefile_FreeBSD Makefile


#	# bison -y eval.y > eval.c
#	/bin/m4: m4sugar/m4sugar.m4: No such file or directory
#	/bin/m4: /boot/home/temp/share/bison/yacc.c: No such file or directory

ln -sv /boot/home/config/share/bison/m4sugar && \
cd ~ && ln -sv config temp && make
