FROM alpine:latest

# Install dependencies for all the languages/tools
RUN apk update && apk add --no-cache \
    build-base \           
    openjdk17 \             
    python3 \               
    py3-pip \  
    git \   
    curl \               
    bash                

CMD [
    "sh", "-c",
    "echo --- Versions --- && \
     g++ --version && \
     java -version && \
     python3 --version && \
     pip --version && \
     git --version"
]