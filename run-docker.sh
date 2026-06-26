#!/usr/bin/env bash
# Build and run Dyna Blaster inside Docker, forwarding the GUI to your host
# X11 display. Works on Linux (native X11) and macOS (XQuartz).
set -euo pipefail

IMAGE=dynablaster
cd "$(dirname "$0")"

echo ">> Building image '$IMAGE'..."
docker build -t "$IMAGE" .

OS="$(uname -s)"
case "$OS" in
  Linux)
    echo ">> Linux detected: using native X11 socket."
    xhost +local:docker >/dev/null 2>&1 || true
    exec docker run --rm \
      -e DISPLAY="${DISPLAY:-:0}" \
      -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
      --network host \
      "$IMAGE"
    ;;
  Darwin)
    echo ">> macOS detected: forwarding to XQuartz over TCP."
    if ! command -v xquartz >/dev/null 2>&1 && [ ! -d "/Applications/Utilities/XQuartz.app" ]; then
      echo "!! XQuartz is required on macOS. Install it with: brew install --cask xquartz"
      echo "   Then log out/in once, open XQuartz, and enable"
      echo "   'Preferences > Security > Allow connections from network clients'."
      exit 1
    fi
    open -a XQuartz || true
    sleep 2
    HOST_IP="$(ipconfig getifaddr en0 2>/dev/null || ipconfig getifaddr en1 2>/dev/null || echo 127.0.0.1)"
    xhost + "$HOST_IP" >/dev/null 2>&1 || true
    exec docker run --rm \
      -e DISPLAY="${HOST_IP}:0" \
      "$IMAGE"
    ;;
  *)
    echo "!! Unsupported OS: $OS"
    exit 1
    ;;
esac
