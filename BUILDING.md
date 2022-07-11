# Building webchain-miner

webchain-miner does not build on GCC 4.8, which means Debian 10 Buster and possibly CentOS 7.

webchain-miner does not support HTTP, so remember to pass `-DWITH_HTTPD=OFF` to `cmake`, otherwise it won't build!

## Install dependencies:

### Ubuntu / Debian 11 Bullseye:
```
sudo apt-get install git build-essential cmake libuv1-dev libssl-dev libhwloc-dev
```

### Fedora:
```
sudo dnf install -y git make cmake gcc gcc-c++ libstdc++-static libuv-static hwloc-devel openssl-devel
```

### Alpine:
```
apk add git make cmake libstdc++ gcc g++ libuv-dev openssl-dev hwloc-dev
```
To install hwloc-dev package you must enable testing repository in /etc/apk/repositories file.

### FreeBSD
```
pkg install git cmake libuv openssl hwloc
```

### CentOS 8
```
sudo dnf install -y epel-release
sudo yum config-manager --set-enabled PowerTools
sudo dnf install -y git make cmake gcc gcc-c++ libstdc++-static hwloc-devel openssl-devel automake libtool autoconf
```

## Build:
```
git clone https://github.com/mintme-com/miner
mkdir xmrig/build && cd xmrig/build
cmake -DWITH_HTTPD=OFF ..
make -j$(nproc)
```

## MacOS / Windows:
For building on MacOS and Windows, please refer to the original XMRig build documentation:

MaxOS (including Apple Silicon): https://xmrig.com/docs/miner/build/macos

Windows: https://xmrig.com/docs/miner/build/windows