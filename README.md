# RLBox WebAssembly Sandboxing Demo

## Project Title

Exploring RLBox Sandboxing with WebAssembly-Based Isolation for Memory-Unsafe C Libraries

## Authors

Vincent Chukwuemeka Ogbonna  
Samuel Abdullahi Abeeb

## Overview

This project is a proof-of-concept demonstrating how RLBox can be used with a WebAssembly/wasm2c backend to isolate memory-unsafe C library code.

The project compares two execution modes:

1. Native execution
   - The host application directly links against the vulnerable C library.
   - Oversized input to the unsafe function causes stack-smashing detection and process termination.

2. RLBox sandboxed execution
   - The same C library is compiled to WebAssembly and converted using wasm2c.
   - The host application invokes the generated module through RLBox.
   - The demo shows sandbox initialization, sandboxed function calls, sandbox-managed memory transfer, and tainted return-value handling.

## Expected Platform

This project is expected to run in:

- GitHub Codespaces
- Ubuntu Linux 22.04 or similar Linux environment

The included binaries were built in GitHub Codespaces/Linux. They may not run directly on macOS or Windows without rebuilding.

## Quickest Way to Run

Open the repository in GitHub Codespaces:

1. Go to the GitHub repository: https://github.com/sam-abdul/rlbox-project.
2. Click **Code**.
3. Select the **Codespaces** tab.
4. Click **Create codespace on main**.
5. Wait for the environment to load.
6. In the terminal, run:

```bash
chmod +x run_demo.sh
./run_demo.sh
```
