#!/bin/bash -
#===============================================================================
#
#          FILE: changeit.sh
#
#         USAGE: ./changeit.sh
#
#   DESCRIPTION: 
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 04/12/2021 05:17:51 PM
#      REVISION:  ---
#===============================================================================

killall dwmblock
sudo make uninstall
sudo make clean install
dwmblocks &

