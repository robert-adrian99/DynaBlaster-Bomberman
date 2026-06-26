# Running Dyna Blaster with Docker

The game is built and run inside a Linux container (Ubuntu 24.04 + SFML 2.6).
Because it is a graphical SFML application, the container needs access to an
X11 display on your host.

## Quick start

```bash
./run-docker.sh
```

The script builds the image and launches the game, picking the right X11
forwarding for your OS.

## Linux

X11 is available natively. The script runs:

```bash
xhost +local:docker
docker run --rm -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --network host dynablaster
```

Or via compose:

```bash
xhost +local:docker
DISPLAY=$DISPLAY docker compose up --build
```

## macOS

macOS has no native X server, so install **XQuartz** once:

```bash
brew install --cask xquartz
```

Then log out and back in, open XQuartz, and enable
**Preferences → Security → "Allow connections from network clients"**.

After that, `./run-docker.sh` will start XQuartz, allow your host IP, and run
the game over TCP.

## Windows

Use WSL2 with an X server (e.g. the built-in WSLg on Windows 11, or VcXsrv),
then follow the Linux instructions from inside WSL.

## Notes

- Audio is not forwarded out of the container; the game runs without sound
  unless you additionally wire up PulseAudio.
- The game loads its textures/fonts from paths relative to the working dir, so
  the container runs the binary from inside the `DynaBlaster/` resource folder.
