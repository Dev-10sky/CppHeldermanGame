
CFLAGS=-ggdb -Wall -Werror
RFLAGS=rm -rf *.o
target = main
cfiles = main.cpp
hfiles = 
txtpath = txt_files
awkpath = awk_files
dotpath = dot_files
binpath = bin
srcpath = src
incpath = include
libpath = lib
libraries = 
imgpath = images
testpath = testing
autopath = automation_outputs

all: $(binpath)/$(target)

$(binpath)/$(target): $(srcpath)/*.cpp
	g++ $(CFLAGS) -I$(incpath) -L$(libpath) $^ -o $@

# object.h: $(awkpath)/object.awk $(txtpath)/object.txt
# 	awk -v pass=h -f $(awkpath)/object.awk $(txtpath)/object.txt > $@
# #	awk -v pass=h -v RS='\r\n' -f $(awkpath)/object.awk $(txtpath)/object.txt > $@
# object.c: $(awkpath)/object.awk $(txtpath)/object.txt
# 	awk -v pass=c1 -f $(awkpath)/object.awk $(txtpath)/object.txt > $@
# 	awk -v pass=c2 -f $(awkpath)/object.awk $(txtpath)/object.txt >> $@
# #	awk -v pass=c1 -v RS='\r\n' -f $(awkpath)/object.awk $(txtpath)/object.txt > $@
# #	awk -v pass=c2 -v RS='\r\n' -f $(awkpath)/object.awk $(txtpath)/object.txt >> $@
# map.png: map.gv
# 	dot -Tpng -o $(imgpath)/map.png $(dotpath)/$<
# map.gv: $(awkpath)/map.awk $(txtpath)/object.txt
# 	awk -v RS='\r\n' -f $(awkpath)/map.awk $(txtpath)/object.txt > $(dotpath)/$@
# success.txt: main $(testpath)/testscript.txt $(autopath)/baseline.txt
# 	./main $(testpath)/testscript.txt > $(autopath)/transcript.txt
# 	cmp $(autopath)/baseline.txt $(autopath)/transcript.txt
# 	mv -f $(autopath)/transcript.txt $(autopath)/success.txt

clean:
#	$(RFLAGS) main object.c object.h $(imgpath)/map.png $(dotpath)/map.gv
	$(RFLAGS) $(binpath)/*