    # minitalk

    Minimal client/server messaging using UNIX signals as a transport layer.

    ## Architecture
    - Server: installs `sigaction` handlers (SA_SIGINFO), rebuilds bytes from SIGUSR1/2 bits, sends ACKs to pace the client.
    - Client: walks each char MSB→LSB, emitting SIGUSR1/2 to encode 0/1 and waits for ACK before the next bit.
    - Protocol: null terminator marks end-of-message; optional small `usleep` guards against handler overload on slow hosts.

    ## Build & Run
    - `make` → builds `server` and `client`.
    - Usage: run `./server` (prints PID), then `./client <pid> "hello"` to send a message.

    ## Technical Notes
    - Asynchronous context: handlers must be async-signal-safe; avoid heap use in handlers.
    - Reliability: per-bit ACK prevents loss; still process-sensitive—avoid heavy CPU loads during tests.
    - Limits: messages are plain text; no binary framing beyond null termination.

    ## Testing Ideas
    - Send long strings and verify integrity; try rapid successive sends; kill server mid-transfer to ensure clean exit paths.

    ## Author
    Oualid Obbad (@oualidobbad)