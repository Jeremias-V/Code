#!/bin/bash
# Personal settings for improved UX

# TouchPad settings
xinput --set-prop 12 'libinput Accel Speed' 0.2

# TrackPoint settings
xinput --set-prop 13 'libinput Accel Speed' 1.0
xinput --set-prop 13 "libinput Accel Profile Enabled" 0 1

# Disable middle click paste
xinput set-button-map 13 1 0
