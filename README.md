Ruben van der Vyver u25007786

Tafadzwa Manyengawana u25370325

Vimbai Chivunga u25136608


https://docs.google.com/document/d/1-L5pyIbCdon_wGuUEeavAAqSYyk3HULjg7hnqKgf0Pk/edit?usp=drivesdk

# Running
## Setting up docker environment
docker build -t taskforge .

docker run --rm -it taskforge bash

## Building and running program
make

./taskforge

## Debugging
gdb ./taskforge

valgrind --leak-check=full --show-leak-kinds=all ./taskforge
