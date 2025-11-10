FROM alpine:latest

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