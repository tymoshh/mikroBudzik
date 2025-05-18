FROM alpine:latest

WORKDIR /app



RUN apk update
RUN apk upgrade

RUN apk add --no-cache g++
RUN apk add --no-cache make
RUN apk add --no-cache curl-dev

RUN apk add curl

RUN apk update
RUN apk upgrade

COPY ./src /app/src
COPY ./Makefile /app
RUN make c

RUN apk del g++
RUN apk del make
RUN apk del libcurl

RUN chmod 777 ./a
CMD ["/app/a"]