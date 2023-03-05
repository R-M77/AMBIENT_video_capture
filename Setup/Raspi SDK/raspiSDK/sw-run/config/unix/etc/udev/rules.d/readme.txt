The attributes of an USB device can be obtained by the command:

udevadm info -q all --attribute-walk -n /dev/bus/usb/.../...

These attributes can be used for writing rules-files.

