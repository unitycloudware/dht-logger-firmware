# Welcome to the DHT Logger Firmware Tutorial!

## Quick links

* [UCW Platform][1]
* [UCW Platform Documentation][2]
* [GitHub][3]
* [Issues][4]

## Description

The DHT Logger Firmware is an example how to implement a data logger for DHTx sensors and how to process data in UCW.

### Quick start

Before you start to use the firmware you need to do following steps:


#### Step 1

Change property UCW_API_HOST pointing to your UCW host. For example when you are running the UCW portal plugin dht-logger 
on your machine, than use the IP address of your machine.

Example: #define UCW_API_HOST	"192.168.0.104"

#### Step 2

You need a device token for communication with the UCW portal over REST API. The token can be found in section Access Tokens
of the UCW project.

Example: #define UCW_API_DEVICE_TOKEN	"jnfb7600j0tqppi6k4179dm0iaop5u93"

#### Step 3

You need a device ID that identifies your device for particular UCW project and it allows to store data in the data stream 'dht-logger'.

Example: #define UCW_API_DEVICE_ID	"3c483804-74ad-4e1d-b367-0afb6eacd503"

[1]: https://unitycloudware.com
[2]: https://docs.unitycloudware.com
[3]: https://github.com/unitycloudware
[4]: https://jira.unitycloudware.com/browse/UCW