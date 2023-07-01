ifconfig -a | grep ether | awk 'FS {print $2}'
