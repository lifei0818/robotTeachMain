#!/bin/bash

filepath=$(find /media -name "update_HR_ROBOT.tar.xz")
echo $filepath

cp $filepath /tmp/
tar xvf /tmp/update_HR_ROBOT.tar.xz -C ./tmp/

cd /tmp/update_HR_ROBOT/
source install.sh

rm -rf /tmp/update_HR_ROBOT*

sudo reboot
