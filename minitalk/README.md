# minitalk

<div align="center">

![Banner](assets/banner.png)
![C Language](https://img.shields.io/badge/Language-C-000000?style=flat&logo=c)
![Communication](https://img.shields.io/badge/IPC-Unix%20Signals-lightblue)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

</div>

## 🎓 Grade
![Grade](assets/grade.png)

## 📘 Description

**minitalk** is a project focused on inter-process communication (IPC) using **UNIX signals**.  
The goal is to build a simple client-server system where messages are sent one bit at a time using only `SIGUSR1` and `SIGUSR2`.

This project demonstrates how to encode characters as binary signals, set up signal handlers, and ensure reliable communication between independent processes.

## 🧠 Key Concepts

- Inter-process communication (IPC)
- Signal handling in Unix (with `signal()` or `sigaction()`)
- Bitwise operations
- Asynchronous event management
- Encoding/decoding characters via signals
- Memory and timing safety

## 🔧 How It Works

- A **server** is launched and displays its PID.
- A **client** sends a string message to the server.
- Each character is sent **bit by bit**, using `SIGUSR1` for binary `1` and `SIGUSR2` for binary `0`.
- The server reconstructs the characters and prints the message.

## 🚀 Usage

### 1. Build the executables

```
make
```

This will compile both `server` and `client`.

### 2. Start the server

```
./server
Server PID: 12345
```

### 3. Send a message from the client

    ./client 12345 "Hello, minitalk!"

Where `12345` is the PID printed by the server.

## 💬 Example

```bash
$ ./server
📡 Server PID: 42782

$ ./client 42782 "42 is awesome!"

# Output on server side:
42 is awesome!
```