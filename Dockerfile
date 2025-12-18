FROM gcc:latest
WORKDIR /app
COPY src/ ./src/
COPY Makefile .
RUN make
ENTRYPOINT ["./investment_sim"]
CMD ["--help"]