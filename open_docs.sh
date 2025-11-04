#!/usr/bin/env bash
set -euo pipefail
ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT_DIR"

INDEX="$ROOT_DIR/docs/html/index.html"

if [ ! -f "$INDEX" ]; then
  echo "Doxygen index not found, generating docs first..."
  ./scripts/generate_docs.sh
fi

if [ -f "$INDEX" ]; then
  echo "Index available at: $INDEX"
else
  echo "Failed to generate Doxygen HTML index."
  exit 2
fi

# Try to open with xdg-open; otherwise serve with python3 http.server
if command -v xdg-open >/dev/null 2>&1; then
  echo "Opening index with default browser..."
  xdg-open "$INDEX" >/dev/null 2>&1 || echo "Failed to open with xdg-open; you can open file://$INDEX manually."
  exit 0
fi

if command -v python3 >/dev/null 2>&1; then
  echo "Serving docs at http://localhost:8000/ (Ctrl-C to stop)"
  cd "$ROOT_DIR/docs/html"
  exec python3 -m http.server 8000
fi

echo "Docs available at file://$INDEX"
exit 0
