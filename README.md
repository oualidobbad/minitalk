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

## Technical Notes
- Bitwise protocol: client sends chars MSB->LSB via SIGUSR1/2; server acks to pace transmission.
- Uses `sigaction` with SA_SIGINFO and restart-safe handlers; avoids global static buffers when possible.
- Timing-sensitive on heavy systems; if messages drop, consider tiny usleep in client after each bit.

## Author
- Oualid Obbad (@oualidobbad)