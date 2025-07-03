#### Password policy

```bash
$ nano /etc/login.defs
...
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
...
$ nano /etc/pam.d/common-password
```

#### Check change hostname

```bash
$ sudo nano /etc/hostname
$ sudo nano /etc/hosts
$ sudo reboot
$ hostname
```

#### Check sudo rules

```bash
$ nano /etc/sudoers.d/sudo_config
```

#### Check crontab of script

```bash
$ sudo crontab -u root -e
```
