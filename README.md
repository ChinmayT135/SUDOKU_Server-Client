<h1>SUDOKU SOLVER using server-client model</h1>

#### Project summary
- Implemented in C++ language, a server-client model which uses a sudoku solving API
- There is an input verification layer in client side so as to make valid requests to server
- Server uses fd_set to process every client connection and it runs as a daemon process in the background
- The server processes the received string and sends back a valid solution, if exists, else it will send the corresponding error message
- The strings that are sent and received on server and client end are encrypted using a custom encryption and decryption function which utilized XOR gate

#### Limitations
- The server can only process a single client connection at one time
- OpenSSL library can be induced to make the API encrption stronger

## How to Run

```bash
$ (clone the repository)
$ cd SERVER
$ make
$ ./server_util run-daemon
$ cd ../CLIENT
$ make
$ ./util
```
`Once you run the util from client, the program has an inbuilt guide for input structure which you can refer to`


# Note:
- This code will only run on LINUX machine.

#### Reviews if any from all the coding enthusiats are always welcomed !!
