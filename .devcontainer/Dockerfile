FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
ENV WASI_SDK_VERSION=21
ENV WASI_SDK_PATH=/opt/wasi-sdk

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    clang \
    lld \
    git \
    curl \
    wget \
    ca-certificates \
    python3 \
    wabt \
    && rm -rf /var/lib/apt/lists/*

RUN cd /opt && \
    wget https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-${WASI_SDK_VERSION}/wasi-sdk-${WASI_SDK_VERSION}.0-linux.tar.gz && \
    tar -xzf wasi-sdk-${WASI_SDK_VERSION}.0-linux.tar.gz && \
    mv wasi-sdk-${WASI_SDK_VERSION}.0 wasi-sdk && \
    rm wasi-sdk-${WASI_SDK_VERSION}.0-linux.tar.gz

ENV PATH="${WASI_SDK_PATH}/bin:${PATH}"

WORKDIR /workspaces/rlbox-project
