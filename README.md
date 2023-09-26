# IAR Export project for STM32CubeF4

A IAR Embedded Workbench example project that can be used as a starting point for running IAR library models (deployed in Edge Impulse studio) on actual hardware.

This example is based on the on the STMicroelectronics [Nucleo-F439ZI](https://www.st.com/en/evaluation-tools/nucleo-f439zi.html) development board. But can be easily swapped out for any of the other boards in the [STM32CubeF4](https://github.com/STMicroelectronics/STM32CubeF4) BSP.

## Getting started

### Setting up the project

Start with the cloning this repository to your computer:
```
$ git clone git@github.com:edgeimpulse/iar-export-stm32.git
```
The STMicroelectronics board support package is hosted and maintained by STMicroelectronics. A link to the BSP is added has a submodule to this repository and can be installed with following command:
```
$ git submodule update --init
```

### Using IAR libraries with Edge Impulse

How to deploy your model to a library that is digestable by IAR Embedded Workbench is described on our documentation page.