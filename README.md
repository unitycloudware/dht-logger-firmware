# Welcome to the DHT Logger Firmware Tutorial!

## Quick links

* [UCW Platform][1]
* [UCW Platform Documentation][2]
* [GitHub][3]
* [Issues][4]

## Description

The DHT Logger Firmware is an example how to implement a data logger for DHTx sensors and how to process data in UCW.

### Quick start

Before you start to use the firmware you need to do following steps in order to set-up connection to the UCW server:


#### Step 1

Change property <b>host</b> for your UCW host. For example when you are running the plugin dht-logger for UCW Portal 
on your machine, than use the IP address of your machine. In case you are running a firewall, please make sure port 
9601 is allowed on firewall.

```
static UCWConfig cfg = {
  .host = 192.168.0.104,
  .port = 9601,
  .isSecuredConnection = false,
  .useMqtt = false,
  .token = "your_token"
};
```

#### Step 2

You need a device token for communication with the UCW portal over REST API. The token can be found in section 
Access Tokens of the UCW project. The scope of the device token has to be READ_WRITE.

```
static UCWConfig cfg = {
  .host = 192.168.0.104,
  .port = 9601,
  .isSecuredConnection = false,
  .useMqtt = false,
  .token = "jnfb7600j0tqppi6k4179dm0iaop5u93"
};
```

#### Step 3

You need a device ID that identifies your device for particular UCW project and it allows to store data in 
the data stream 'dht-logger'.

Example: #define DEVICE_ID   "3c483804-74ad-4e1d-b367-0afb6eacd503"

[1]: https://unitycloudware.com
[2]: https://docs.unitycloudware.com
[3]: https://github.com/unitycloudware
[4]: https://jira.unitycloudware.com/browse/UCW