FROM alpine:latest

# Install dependencies for all the languages/tools
RUN apk update && apk add --no-cache \
    build-base \            # Includes g++, gcc, make
    openjdk17 \             # Install Java OpenJDK 17
    python3 \               # Python 3
    py3-pip \               # pip for Python
    git \                   # Git
    curl \                  # Optional, from your original Dockerfile
    bash                    # Useful for scripting inside container

# Set default CMD
CMD [
    "sh", "-c",
    "echo --- Versions --- && \
     g++ --version && \
     java -version && \
     python3 --version && \
     pip --version && \
     git --version"
]