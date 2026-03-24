# minitalk

## Description
Minimal client/server message passing over UNIX signals.

## Features
- Sends strings bit-by-bit via SIGUSR1/2 with acknowledgments.
- Robust parsing and basic error handling.

## Technologies Used
- C, POSIX signals, Makefile.

## Installation
- Run `make` to build `server` and `client`.

## Usage
- Start `./server`, note PID, then `./client <pid> "hello"`.

## Example
- `./client 4242 "Hi"` sends "Hi" to the server.

## Author
- Oualid Obbad (@oualidobbad)