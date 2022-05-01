#!/bin/sh

set -ex

qemu-system-aarch64 -M raspi3b -serial stdio -kernel kernel8.img
