# 📁 `minitalk`

A client-server communication program using UNIX signals to transmit characters. Data is sent bit-by-bit via `SIGUSR1` and `SIGUSR2`.

## Features
- Sends and receives messages between two processes using only signals
- Encodes ASCII data into binary
- Handles message reconstruction on the server

## Usage
```bash
# In one terminal:
./server

# In another:
./client <server_pid> "Hello there!"
```
## Why
To explore low-level interprocess communication and signal handling in UNIX systems.
