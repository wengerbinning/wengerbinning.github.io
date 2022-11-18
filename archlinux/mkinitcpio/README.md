mkinitcpio /etc/
-----------------------------------------------------------------------------
mkinitcpio /etc/mkinitcpio.conf

mkinitcpio /etc/mkinitcpio.d/

mkinitcpio /etc/initcpio/
mkinitcpio /etc/initcpio/hooks/
mkinitcpio /etc/initcpio/install/

mkinitcpio /usr/bin/
-----------------------------------------------------------------------------
mkinitcpio /usr/bin/lsinitcpio
mkinitcpio /usr/bin/mkinitcpio

mkinitcpio /usr/lib/
-----------------------------------------------------------------------------
mkinitcpio /usr/lib/initcpio/
mkinitcpio /usr/lib/initcpio/init
mkinitcpio /usr/lib/initcpio/init_functions
mkinitcpio /usr/lib/initcpio/shutdown
mkinitcpio /usr/lib/initcpio/functions

mkinitcpio /usr/lib/initcpio/hooks/
mkinitcpio /usr/lib/initcpio/hooks/consolefont
mkinitcpio /usr/lib/initcpio/hooks/keymap
mkinitcpio /usr/lib/initcpio/hooks/memdisk
mkinitcpio /usr/lib/initcpio/hooks/resume
mkinitcpio /usr/lib/initcpio/hooks/shutdown
mkinitcpio /usr/lib/initcpio/hooks/sleep
mkinitcpio /usr/lib/initcpio/hooks/usr

mkinitcpio /usr/lib/initcpio/install/
mkinitcpio /usr/lib/initcpio/install/autodetect
mkinitcpio /usr/lib/initcpio/install/base
mkinitcpio /usr/lib/initcpio/install/block
mkinitcpio /usr/lib/initcpio/install/consolefont
mkinitcpio /usr/lib/initcpio/install/filesystems
mkinitcpio /usr/lib/initcpio/install/fsck
mkinitcpio /usr/lib/initcpio/install/hostdata
mkinitcpio /usr/lib/initcpio/install/keyboard
mkinitcpio /usr/lib/initcpio/install/keymap
mkinitcpio /usr/lib/initcpio/install/memdisk
mkinitcpio /usr/lib/initcpio/install/modconf
mkinitcpio /usr/lib/initcpio/install/resume
mkinitcpio /usr/lib/initcpio/install/sd-shutdown
mkinitcpio /usr/lib/initcpio/install/sd-vconsole
mkinitcpio /usr/lib/initcpio/install/shutdown
mkinitcpio /usr/lib/initcpio/install/sleep
mkinitcpio /usr/lib/initcpio/install/strip
mkinitcpio /usr/lib/initcpio/install/usr

mkinitcpio /usr/lib/initcpio/udev/
mkinitcpio /usr/lib/initcpio/udev/01-memdisk.rules

mkinitcpio /usr/share/mkinitcpio/
mkinitcpio /usr/share/mkinitcpio/example.preset
mkinitcpio /usr/share/mkinitcpio/hook.preset

mkinitcpio /usr/lib/kernel/
mkinitcpio /usr/lib/kernel/install.d/
mkinitcpio /usr/lib/kernel/install.d/50-mkinitcpio.install

mkinitcpio /usr/lib/systemd/
mkinitcpio /usr/lib/systemd/system/
mkinitcpio /usr/lib/systemd/system/mkinitcpio-generate-shutdown-ramfs.service
mkinitcpio /usr/lib/systemd/system/shutdown.target.wants/
mkinitcpio /usr/lib/systemd/system/shutdown.target.wants/mkinitcpio-generate-shutdown-ramfs.service

mkinitcpio /usr/lib/tmpfiles.d/
mkinitcpio /usr/lib/tmpfiles.d/mkinitcpio.conf



mkinitcpio /usr/share/
-----------------------------------------------------------------------------
mkinitcpio /usr/share/bash-completion/
mkinitcpio /usr/share/bash-completion/completions/
mkinitcpio /usr/share/bash-completion/completions/lsinitcpio
mkinitcpio /usr/share/bash-completion/completions/mkinitcpio

mkinitcpio /usr/share/zsh/
mkinitcpio /usr/share/zsh/site-functions/
mkinitcpio /usr/share/zsh/site-functions/_mkinitcpio

mkinitcpio /usr/share/libalpm/
mkinitcpio /usr/share/libalpm/hooks/
mkinitcpio /usr/share/libalpm/hooks/60-mkinitcpio-remove.hook
mkinitcpio /usr/share/libalpm/hooks/90-mkinitcpio-install.hook
mkinitcpio /usr/share/libalpm/scripts/
mkinitcpio /usr/share/libalpm/scripts/mkinitcpio-install
mkinitcpio /usr/share/libalpm/scripts/mkinitcpio-remove

mkinitcpio /usr/share/man/
mkinitcpio /usr/share/man/man1/
mkinitcpio /usr/share/man/man1/lsinitcpio.1.gz
mkinitcpio /usr/share/man/man5/
mkinitcpio /usr/share/man/man5/mkinitcpio.conf.5.gz
mkinitcpio /usr/share/man/man8/
mkinitcpio /usr/share/man/man8/mkinitcpio.8.gz






mkinitcpio
---
一个制作initramfs镜像的脚本工具。
---

/etc/initcpio/hooks:/usr/lib/initcpio/hooks
/etc/initcpio/install:/usr/lib/initcpio/initall


/usr/lib/initcpio/functions


/etc/mkinitcpio.conf