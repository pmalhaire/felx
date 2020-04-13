# About cpp

## intro on process

to run

```
gcc -o process process.c
# optional if needed
chmod +x ./process
./process
```


## intro to thread

### thread


```
cd cpp
g++ -std=c++2a -Wall -Werror -lpthread -o thread thread.cpp
./thread
```

### pointer

```
cd cpp
g++ -std=c++2a -Wall -Werror -lpthread -o th_pointer th_pointer.cpp
./th_pointer
```

### mutex

```
cd cpp
g++ -std=c++2a -Wall -Werror -lpthread -o th_mutex th_mutex.cpp
./th_mutex
```

### no delay

```
cd cpp
g++ -std=c++2a -Wall -Werror -lpthread -o th_nodelay th_nodelay.cpp
./th_nodelay

# test
for i in {1..10};do ./th_nodelay;done

# no waranty that foo will be executed first
```
