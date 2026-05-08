#!/bin/bash

echo "======================================"
echo "RLBox WebAssembly Sandboxing Demo"
echo "======================================"
echo

echo "1. Running native baseline..."
echo "Expected behavior: native_app should abort with stack-smashing detection."
echo "This crash is intentional and demonstrates the unsafe native baseline."
echo

./native_app

echo
echo "--------------------------------------"
echo

echo "2. Running RLBox sandboxed demo..."
echo "Expected behavior: sandboxed_app should complete successfully."
echo

./sandboxed_app

echo
echo "Demo complete."
