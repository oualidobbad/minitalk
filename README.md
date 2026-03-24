    # minitalk

    Minimal client/server messaging over UNIX signals (SIGUSR1/2) with per-bit acknowledgments.

    ## Project Overview
    - What it does: `server` rebuilds bytes from incoming signals; `client` encodes a string bit-by-bit to a target PID.
    - Use cases: IPC without sockets/pipes; practice with signals and async constraints.
    - Problem solved: reliable bitwise messaging over unreliable signal timing by pacing with ACKs.

    ## Architecture & Design
    - Server (`server.c`): `sigaction` + SA_SIGINFO handler tracks sender PID, accumulates bits into a char, prints when 8 bits received, then ACKs sender with SIGUSR1.
    - Client (`client.c`): for each char (MSB→LSB), sends SIGUSR1 for 1 and SIGUSR2 for 0; busy-waits on a global `flag` set by server ACK before sending next bit.
    - Protocol: null terminator not explicitly sent; client stops at end of string. Server resets state if PID changes mid-stream.

    ## Core Concepts (with code)
    - Bit packing on server:
    ```c
    // server.c
    static int bite = 7; static char c = 0;
    if (sig == SIGUSR1) c |= (1 << bite);
    if (--bite < 0) { write(1, &c, 1); bite = 7; c = 0; }
    kill(current_pid, SIGUSR1); // ACK
    ```
    - Client pacing on ACK:
    ```c
    // client.c
    if ((c >> i & 1) == 1) kill(pid, SIGUSR1); else kill(pid, SIGUSR2);
    while (flag == 0); // waits for server ACK
    flag = 0;
    ```

    ## Code Walkthrough
    1) Server startup: installs handlers for SIGUSR1/2, prints PID, then spins.
    2) On each signal: update bit accumulator, emit char every 8 bits, ACK sender PID.
    3) Client: parse PID via `ft_atoi`, install ACK handler, loop over message bytes, send bits with pacing.

    ## Installation & Setup
    - `make` → builds `server` and `client`.
    - Dependencies: libc, signals; no extra libs.

    ## Usage Guide
    ```bash
    ./server    # prints PID
    ./client <pid> "hello world"
    ```

    ## Technical Deep Dive
    - Reliability: ACK per bit prevents overruns but uses busy-wait in client (CPU spin).
    - Concurrency: server handler must stay async-signal-safe; only uses `write`/`kill` and static storage.
    - Limits: no framing for binary blobs; no end-of-message signal besides process exit; no retransmit on lost signals.

    ## Improvements & Future Work
    - Add explicit EOT marker (send '\0') and handle multi-message sessions.
    - Replace busy-wait with `sigsuspend` or `pause` + sigmask to reduce CPU.
    - Add minimal error handling for bad PIDs and long messages.

    ## Author
    Oualid Obbad (@oualidobbad)