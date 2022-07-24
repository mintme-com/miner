# webchain-miner

webchain-miner is a high performance Webchain (WEB) CPU miner, with official support for Windows.
Originally based on XMRig with changes that allow mining WEB.

#### Table of contents
* [Features](#features)
* [Download](#download)
* [Building](#building)
* [Usage](#usage)
* [Algorithm variations](#algorithm-variations)
* [Common Issues](#common-issues)
* [Other information](#other-information)
* [Donations](#donations)
* [Contacts](#contacts)

## Features
* High performance.
* Official Windows support.
* Small Windows executable, without dependencies.
* Support for backup (failover) mining server.
* keepalived support.
* Command line options compatible with XMRig.
* Smart automatic [CPU configuration](https://github.com/xmrig/xmrig/wiki/Threads).
* It's open source software.

## Download
* Binary releases: https://github.com/webchain-network/webchain-miner/releases

## Building
webchain-miner does not support HTTP, so remember to pass `-DWITH_HTTPD=OFF` to `cmake`, otherwise it won't build!

Also, it requires a fairly modern distribution. If a distro release is specified below, that means it's confirmed to not build on the previous version.
```
# Download dependencies:

# Debian 11 Bullseye / Ubuntu (see #34):
sudo apt-get install git build-essential cmake libuv1-dev libssl-dev libhwloc-dev
# Fedora:
sudo dnf install -y git make cmake gcc gcc-c++ libstdc++-static libuv-static hwloc-devel openssl-devel
# Alpine: (to install hwloc-dev package you must enable
# testing repository in /etc/apk/repositories file)
apk add git make cmake libstdc++ gcc g++ libuv-dev openssl-dev hwloc-dev
# FreeBSD:
pkg install git cmake libuv openssl hwloc
# CentOS 8:
sudo dnf install -y epel-release
sudo yum config-manager --set-enabled PowerTools
sudo dnf install -y git make cmake gcc gcc-c++ libstdc++-static hwloc-devel openssl-devel automake libtool autoconf


# Clone and build
git clone https://github.com/mintme-com/miner
mkdir miner/build && cd miner/build
cmake -DWITH_HTTPD=OFF ..
make -j$(nproc)
```

For building on MacOS and Windows, please refer to the original XMRig build documentation:

MacOS (including Apple Silicon): https://xmrig.com/docs/miner/build/macos

Windows: https://xmrig.com/docs/miner/build/windows

## Usage
Minimal set of options:
```
webchain-miner -o <pool_address> -u <0xYOUR_PUBKEY> -p <password>
```

All available options:
```
  -o, --url=URL            URL of mining server
  -O, --userpass=U:P       username:password pair for mining server
  -u, --user=USERNAME      username for mining server
  -p, --pass=PASSWORD      password for mining server
  -t, --threads=N          number of miner threads
  -k, --keepalive          send keepalived for prevent timeout (need pool support)
  -r, --retries=N          number of times to retry before switch to backup server (default: 5)
  -R, --retry-pause=N      time to pause between retries (default: 5)
      --cpu-affinity       set process affinity to CPU core(s), mask 0x3 for cores 0 and 1
      --cpu-priority       set process priority (0 idle, 2 normal to 5 highest)
      --no-huge-pages      disable huge pages support
      --no-color           disable colored output
      --variant            algorithm PoW variant
      --donate-level=N     donate level, default 5% (5 minutes in 100 minutes)
      --user-agent         set custom user-agent string for pool
  -B, --background         run the miner in the background
  -c, --config=FILE        load a JSON-format configuration file
  -l, --log-file=FILE      log all output to a file
  -S, --syslog             use system log for output messages
      --max-cpu-usage=N    maximum CPU usage for automatic threads mode (default 75)
      --safe               safe adjust threads and av settings for current CPU
      --print-time=N       print hashrate report every N seconds
      --api-port=N         port for the miner API
      --api-access-token=T access token for API
      --api-worker-id=ID   custom worker-id for API
  -h, --help               display this help and exit
  -V, --version            output version information and exit
```

* Also you can use configuration via config file, default **config.json**. You can load multiple config files and combine it with command line options.

## Common Issues
### HUGE PAGES unavailable
* Run webchain-miner as Administrator.
* webchain-miner automatically enables SeLockMemoryPrivilege for current user, but reboot or sign out still required. [Manual instruction](https://msdn.microsoft.com/en-gb/library/ms190730.aspx).

## Other information
* No HTTP support, only stratum protocol support.
* No TLS support.
* Default donation 5% (5 minutes in 100 minutes) can be reduced to 0% via command line option `--donate-level`.


### Maximum performance checklist
* Idle operating system.
* Do not exceed optimal thread count.
* Try setup optimal cpu affinity.
* Enable fast memory (Large/Huge pages).

## Contacts
* support@webchain.network
