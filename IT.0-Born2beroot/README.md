# Born2beRoot Project

## Overview

Born2beroot is a system administration exercise that focuses on creating a secure server environment in a virtual machine.

## Constraints and topics covered

### Virtualization
The VM must be set up using **VirtualBox**.

### Operating System
The OS must be **Debian** (latest stable version). 

### Security / User Management
The server must be configured with strict rules:
- **SSH** hardening - custom port, no root login
- restricted **`sudo`** access
- **firewall** configuration
- strong **password** policy enforcement
- encrypted **partitions**  

### Services
A **cronjob** indicating general system information must be set up, and keep working each 10 minutes including at reboot.

### General Knowledge
In addition to the above, **general questions** about system administration must be answered: what is a package manager, how does a firewall work, what is SELinux/AppArmor, etc.
