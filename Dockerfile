FROM debian:bullseye
# Does not build on Buster! Old GCC 4.8!

RUN apt-get update && apt-get install -y wget git build-essential cmake libuv1-dev libssl-dev libhwloc-dev

RUN adduser --gecos "" --add_extra_groups --disabled-password user
USER user
WORKDIR /home/user

#RUN git clone --depth=1 https://github.com/mintme-com/miner
COPY --chown=user:user . /home/user/miner

# webchain-miner is a fork of XMRig, but it does not support HTTP!
RUN mkdir miner/build && cd miner/build && cmake -DWITH_HTTPD=OFF .. && make -j$(nproc)

ENTRYPOINT ["/home/user/miner/build/webchain-miner"]
