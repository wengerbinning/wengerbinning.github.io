sudo pacman -S syslog-ng



SYSLOG=/srv/syslog




cat << EOF >> /etc/syslog-ng/syslog-ng.conf

source network { udp(); };
destination remote { file("/srv/syslog/remote-system.log"); };

log {
    source(network);
    destination(remote);
};

EOF





sudo systemctl start syslog-ng@default






systemed




test.service

[Service]
Environment="var=val"
EnvironmentFile=/etc/default


