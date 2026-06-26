# Dyna Blaster - Bomberman, containerized for Linux/SFML.
# The game is an SFML GUI app, so the container needs access to an X11 display
# on the host (see DOCKER.md / run-docker.sh).
FROM ubuntu:24.04

RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential \
        cmake \
        libsfml-dev \
        ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . /app

RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    && cmake --build build -j"$(nproc)"

# Textures, fonts and audio are loaded via paths relative to the working dir,
# so run the binary from inside the resource folder.
WORKDIR /app/DynaBlaster
RUN cp /app/build/DynaBlaster ./DynaBlaster

CMD ["./DynaBlaster"]
