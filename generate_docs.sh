#!/usr/bin/env bash
set -euo pipefail
ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT_DIR"

if ! command -v doxygen >/dev/null 2>&1; then
  echo "ERROR: doxygen not found. Install it (Ubuntu: sudo apt install doxygen) and retry."
  exit 1
fi

if [ ! -f Doxyfile ]; then
  echo "ERROR: Doxyfile not found in project root."
  exit 2
fi

echo "Running doxygen (Doxyfile)..."
doxygen Doxyfile

if [ -f "${ROOT_DIR}/docs/html/index.html" ]; then
  echo "Doxygen HTML generated at: ${ROOT_DIR}/docs/html/index.html"
else
  echo "Doxygen finished but index not found. Check Doxygen output for errors."
fi
