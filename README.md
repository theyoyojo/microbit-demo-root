# microbit-demo-root

A component of a micro:bit demonstration. Code for an admin node.

[The other component](https://github.com/theyoyojo/microbit-demo-user)

### How to compile and install:

See [this Google doc](https://docs.google.com/document/d/1ZT9YcPsR-To2kQpRb6Q6RIYCqXsT9LDIWzZImJKM-Wg/edit) for instructions.

*Better formatted instructions in markdown coming soon.*

===

If your environment is already setup, just the following to download required libraries:

```bash
yotta target bbc-microbit-classic-gcc
yotta install lancaster-university/microbit

```

#### Important note:
In file microbit-demo-root/yotta_modules/microbit_dal/inc/core/MicroBitConfig.h
Change line 199 from:
```
#define MICROBIT_BLE_ENABLED                    1
```
to
```
#define MICROBIT_BLE_ENABLED                    0
```
In order to enable the radio functionality of the device (which is mutually exclusive with bluetooth functionality)


And finally `yotta build` to generate your .hex file.

===

Disclaimer: This project may have unknown issues.