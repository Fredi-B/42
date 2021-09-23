# Born2beroot
## Clarifying terms and definitions
	  
### VirtualBox

* kind of simulating hardware
* sandbox
* different OSs 

### Debian vs. CentOS

Debian | CentOS
---|---
not an enterprise os | enterprise os --> stable af and long term support for big companies, military... [Wiki](https://de.wikipedia.org/wiki/CentOS#Enterprise-Betriebssystem)
easy to upgrade version locally | hard to locally upgrade, rather install new version and delete old
good for desktop evnironment | good for servers

####Commands

Command | purpose
---|---
uname -a (or head -n 2 /etc/os-release) | to see that it's Debian (see PDF p.10)


### AppArmor and SELinux

AppArmor | SELinux
---|---
"AppArmor is offered in part as an alternative to SELinux, which critics consider difficult for administrators to set up and maintain." [Wiki](https://en.wikipedia.org/wiki/AppArmor#Details) | 
AppArmor is a Linux Kernel security module, limiting what parts of the system the application can access. (though not a sandbox, two apps with the same resource could interact.) [cf.](https://security.stackexchange.com/questions/195346/comparison-between-firejail-and-apparmor) | "SELinux can potentially control which activities a system allows each user, process, and daemon, with very precise specifications." [Wiki](https://en.wikipedia.org/wiki/Security-Enhanced_Linux#Use_scenarios)

#### Commands

Command | purpose
---|---
sudo aa-status | see status (about profiles, complain, enforce mode...)
sudo service apparmor status | see if active


### aptitude vs apt

[apt](https://en.wikipedia.org/wiki/APT_(software)) | [aptitude](https://en.wikipedia.org/wiki/Aptitude_(software))
---|---
Advanced Package Tool | 
builds upon low level tool dpkg (debian package) | front-end to apt with GUI and CLI 
handles installation and removal of software (packages with their dependencies)  | full replacement of apt (can be used interchangeably) and gives more information


### SSH service

#### Commands

command | purpose
---|---
ssh -p4242 fbechtol@localhost / ip | connect to my vm with the mac terminal
ip address | to see ip addres, e.g. inet 10.0.2.15
sudo service ssh status |  
sudo nano /etc/ssh/sshd_config | PermitRootLogin yes/no (shows the port 4242 as well)

### UFW

uncomplicated firewall

#### Commands

command | purpose
---|---
sudo ufw status (numbered) | see status and (numbered) ports 
sudo ufw allow \<port> | add a rule / port
sudo ufw delete \<number> | delete a rule

### Hostname

command | purpose
---|---
sudo nano /etc/hosts & /etc/hostname | edit hostname 

### Password policy

command | purpose
---|---
sudo chage -l \<login> | see policy
sudo chage -m \<days> \<login> | set minimum number of days 
sudo chage -M \<days> \<login> | set maximum number of days
sudo chage -W \<days> \<login> | set expiration warning days
nano /etc/login.defs | set above settings for new users [(line 160)](https://www.server-world.info/en/note?os=Debian_10&p=password)
nano /etc/security/pwquality.conf | set the rest of the policy, e.g. at least 10 characters long, an uppercase ...

**PWs**

* root: Fbechtol42
* fbechtol / sudo: Heilbronn42

### Users and groups

command | purpose
---|---
sudo groupadd \<groupname> | add a group
sudo adduser \<username> | add a user
sudo adduser \<username> \<groupname> | add user to a group
getent group \<groupname> | list members of a group
groups (\<username>) | list all groups a user is a member of
cat /etc/group (\| grep \<groupname>) | list all groups (check for certain group) 
cat /etc/passwd (\| grep \<username>) | list all user (check for certain user)

### Sudo

command | purpose
---|---
mkdir /var/log/sudo | create folder to archive sudo actions
touch /etc/sudoers.d/sudoconfig | create file to configure requirements for sudo group

#### Configure sudo group

* Defaults	badpass_message="<custom message>"       
* Defaults 	log\_input,log\_output                      
* Defaults 	iolog\_dir="/var/log/sudo"                  
* Defaults 	requiretty 
* Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"

### TTY

* teletypewriter
* pseudo-teletype multiplexor (leader)
 * organizes the pseudo-teletypes (PTS) (follower)
* require tty: daemons, scripts... can't use sudo commands. tty is required ^^
command | purpose
---|---
tty | print the name of the device file that your pseudo-teletype follower is using to interface to the leader, a.k.a. the number of your terminal
who | list information for all logged in users [(howtogeek)](https://www.howtogeek.com/428174/what-is-a-tty-on-linux-and-how-to-use-the-tty-command/)

### monitoring.sh

* shell script
* "a file containing a series of commands" [(link)](https://linuxways.net/debian/how-to-create-and-run-a-shell-script-in-debian-10/)
* path: /etc/monitoring.sh

command | purpose
---|---
uname -a | shows #architecture
grep "physical id" /proc/cpuinfo \| sort \| uniq \| wc -l | count physical ids aka #processors 
grep "cpu core" /proc/cpuinfo \| wc -l | count #virtual processors
free --mega \| awk 'NR==2 {printf "%d/%dMB (%.2f%%)", $3,$2, ($3*100/$2)}' |  --mega displays free in MB, NR==2 row nr. 2, $3 -> columncolumn nr. 3
df --total -h \| awk '$NF=="-" {printf "%d/%dGB (%s)\n", $3*1000,$2,$5}' | --total adds all rows, - h makes it "Human-readable" \| NF=="-" last column equals "-"
mpstat \| awk 'NR==4 {printf "%.1f%%", 100 - $13}' | sudo apt install sysstat for mpstat \| 100% - idle (column 13)
who -b \| awk '{print $3" "$4}' | who -b shows time of last boot \| print column 3 and 4 with a space in between ($3,$4 would do, too)
 if (lsblk \| grep 'LVM' \| wc -l) != 0 then echo "yes" else echo "no" fi (different syntax which md didn't like)| see if there's more than LVM partitions
ss -s \| awk 'NR==2 {print 'dollar'4}' \| sed 's/,//g' | ss -s shows TCP (among others) \| print 2. row 4. column \| substitute (s) the ',' with nothing
(who \| awk '{print $1}' \| uniq \| wc -l) | counts uniq users (1. column of who)
hostname -I | IPv4 address 
ip a \| grep 'ether' \| awk '{print "("$2")"}' | grep MAC address in ip a
cat /var/log/auth.log \| awk '{if ($5=="sudo:"){print}}' \| wc -l | count every line in the auth.log file with sudo in the 5. column  


### Bonus

* upgraded top to htop 
 * similar to the task manager


## Commands

* **su -**
	* change user to root
	* pw required
* **apt install \***
	* install pcks:
		* sudo
		* adduser
	* apt list --installed <- to see all installed pkgs
* **$ sudo reboot**

* **lsblk**
 * display partitions

 
## signature:
 
* shasum FredOS.vdi > signature.txt
* vimdiff signature.txt test.txt

