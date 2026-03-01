FROM alpine:latest AS builder

# Install dependencies
RUN apk update && apk upgrade && apk add make g++-arm-none-eabi

WORKDIR /app

# Copy source files
COPY App /app/App/
COPY Core /app/Core/
COPY Drivers /app/Drivers/
COPY Middlewares /app/Middlewares/
COPY USB_DEVICE /app/USB_DEVICE/
COPY Makefile /app/
COPY Makefile.local /app/
COPY startup_stm32h723xx.s /app/
COPY STM32H723XG_FLASH.ld /app/

# Build project
RUN make GCC_PATH=/usr/bin