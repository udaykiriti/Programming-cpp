FROM alpine:latest
RUN apk add --no-cache curl
CMD ["echo", "Hello from a random Dockerfile!"]