# IAR Export project for STM32CubeF4

An IAR Embedded Workbench example project that can be used as a starting point for running IAR library models (deployed in Edge Impulse studio) on actual hardware.

This example is based on the on the STMicroelectronics [Nucleo-F429ZI](https://www.st.com/en/evaluation-tools/nucleo-f429zi.html), which is not longer in production. The [Nucleo-F439ZI](https://www.st.com/en/evaluation-tools/nucleo-f439zi.html) development board is it's successor and also suitable to run this project. But as this example doesn't rely heavily on processor architecture or pheripherals, the STM device can be easily swapped out for any of the other boards in the [STM32CubeF4](https://github.com/STMicroelectronics/STM32CubeF4) BSP.

## Getting started

For general documentation on how to start with IAR library deployments visit the [documentation](https://docs.edgeimpulse.com/docs/run-inference/iar-library) page on Edge Impulse.

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

> ⚠️ **Location of the unzipped library folder**
>
> The unzipped library folder should be placed in the root folder of the project

## IAR Project set up

Following project settings are already configured in current project but must be configured when starting a new project:

- CMSIS should be disabled in the project settings
- Library selection set to LIBC++
- Configure C++
- Set HEAP size in .icf (linker) file to a reasonable number
- Stack size should be at least 2048 bytes

This are the heap and stack sizes for STM32F4xx:

```
define symbol __ICFEDIT_size_cstack__ = 0x800;
define symbol __ICFEDIT_size_heap__   = 0x20000;
```

Size of the heap memory needed depends on the size of the model. Consult the RAM number in the deployment page in Edge Impulse studio for the minimal required heap memory needed for your application.

## Running and validating

For importing and building the firmware including an Edge Impulse model follow the instructions from the online [documentation](https://docs.edgeimpulse.com/docs/run-inference/iar-library).
To view the inference results on device, open a serial terminal (like Tera Term on Windows or Minicom on Linux / Mac). Serial settings should be configured as follows: 115200 baudrate 8N1.