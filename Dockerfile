FROM gcc:latest
WORKDIR /app
COPY . .
RUN gcc -o simulator *.c
CMD ["./simulator"]