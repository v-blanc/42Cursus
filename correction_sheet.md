# Born2beroot Correction

Sheet pour la correction du projet Born2beroot.

## Réponses

#### Qu'est-ce qu'une VM ?

Une VM est un *environnement logiciel* qui émule un *ordinateur physique*, permettant d'exécuter un *OS* comme sur une machine réelle grâce à un hyperviseur.  
Cet hyperviseur virtualise les ressources matérielles de l'hôte (processeur, mémoire, disque) et crée un environnement isolé.

#### Pourquoi avoir choisi cet OS ?

J'ai choisi Debian car le sujet lui même indique que ce dernier est plus simple à prendre en main, et il y a plus de ressources sur Debian que sur Rocky.

#### Debian vs Rocky

Debian est plus général et populaire, surtout pour les particuliers et les serveurs, tandis que Rocky est pour les entreprises avec des exigences de stabilité et de long terme.

#### Quel est le but des VM ?

Leur but est de fournir un environnement d'exécution indépandant de la plateforme, et donc de pouvoir utiliser le même code sur toutes les plateformes.

#### Apt vs Aptitude

Aptitude est une version améliorée d'apt.  
Apt est un gestionnaire de paquets bas niveau et aptitude est un gestionnaire de paquets de haut niveau.

#### Qu'est-ce que APPArmor ?

C'est un module de sécurité dans le noyau Linux qui permet à l'administrateur système de restreindre les capacités d'un programme.

#### Qu'est-ce que LVM ?

C'est un gestionnaire de volumes logiques.  
Il fournit une méthode d'allocation d'espace sur les périphériques de stockage de masse, plus flexible que les schémas de partitionnement conventionnels pour le stockage des volumes.

## Commandes

#### Check signature.txt

```bash
$ cat signature.txt
...
$ shasum machinename.vdi
...
```

#### Check d'interface graphique

```bash
$ ls /usr/bin/*session
/usr/bin/dbus-run-session
```

#### Check UFW

```bash
$ sudo ufw status
Status: active
...

$ sudo service ufw status
...
Active: active
...
```

#### Check SSH

```bash
$ sudo service ssh status
...
Active: active
...
```

#### Check OS

```bash
$ uname --kernel-version
SMP Debian X.XX.XXX-X
```

#### Check user and group

```bash
$ getent group sudo
sudo:x:27:vblanc
$ getent group user42
user42:x:1001:vblanc
```

#### Add user and group

```bash
$ sudo useradd name_user
$ sudo addgroup evaluating
$ sudo adduser name_user evaluating
```

#### Check hostname

```bash
$ hostname
```

#### Check change hostname

```bash
$ sudo nano /etc/hostname
$ sudo nano /etc/hosts
$ sudo reboot
$ hostname
```

#### Check partitions

```bash
$ lsblk
```

#### Check sudo

```bash
$ which sudo
```

#### Add user to sudo group

```bash
$ sudo adduser name_user sudo
$ getent group sudo
```

#### Check sudo rules

```bash
$ nano /etc/sudoers.d/sudo_config
```

#### Check sudo logs

```bash
$ cd
$ cd /var/log/sudo
$ ls
$ cat sudo_config
```

#### Check UFW

```bash
$ dpkg -s ufw
...
Status: install ok installed
...
$ sudo service ufw status
...
Active: active
...
```

#### Check UFW active rules

```bash
$ sudo ufw status numbered
```

#### Check rule creation

```bash
$ sudo ufw allow 8080
$ sudo ufw status numbered

$ sudo ufw delete num_rule (ie 1, 2, 3, ...)
$ sudo ufw status numbered
```

#### Check SSH

```bash
$ which ssh
$ sudo service ssh status
$ ssh root@localhost -p 4242
(No permission)
$ ssh newuser@localhost -p 4242
```

#### Check crontab of script

```bash
$ sudo crontab -u root -e
```
