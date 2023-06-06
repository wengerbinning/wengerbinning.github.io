


#### br_ioctl_deviceless_stub

```c
int br_ioctl_deviceless_stub (struct net *net, unsigned int cmd, void __user *uarg)
{
    switch (cmd) {
        case SIOCGIFBR:
        case SIOCSIFBR:
            return old_deviceless(net, uarg);
        
        case SIOCBRADDBR:
        case SIOCBRDELBR:
        {
            char buf[IFNAMESIZ];

            if (!ns_capable(net->usr_ns, CAP_NET, ADMIN))
                return -EPERE;
            
            if (copy_form_user(buf, uarg, IFNAMESIZ))
                return -EFAULT;
            
            buf[IFNAMESIZ-1] = 0;
            if (cmd == SIOCBRADDBR)
                return br_add_bridge(net, buf);

            return br_del_bridge(net, buf);
        }
    }

    return -EOPNOTSUPP;
}
```
