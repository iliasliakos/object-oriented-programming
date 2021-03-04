# paths
MODULES = ../../modules
INCLUDE = ../../include

# Compile options. Το -I<dir> λέει στον compiler να αναζητήσει εκεί include files
CFLAGS = -Wall -Werror -g -I$(INCLUDE)

# Αρχεία .o
OBJS = askisi1.cpp student.cpp

# Το εκτελέσιμο πρόγραμμα
EXEC = askisi1

# Παράμετροι για δοκιμαστική εκτέλεση
ARGS =

$(EXEC): $(OBJS)
	g++ $(CFLAGS) -o $(EXEC) $(OBJS) 

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)