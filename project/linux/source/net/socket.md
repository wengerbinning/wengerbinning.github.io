








## 数据对象

#### socket_file_ops

```c
static const struct file_operations socket_file_ops = {
    .owner = THIS_MODULE,
    .llseek = no_llseek,
    .read_iter = sock_read_iter,
    .write_iter = sock_write_iter,
    .poll = sock_poll,
    .unlocked_ioctl = sock_ioctl,
#ifdef COFNIG_COMPAT
    .compat_ioctl = compat_sock_ioctl,
#endif /* COFNIG_COMPAT */
    .mmap = sock_mmap,
    .release = sock_close,
    .fasync = sock_fasync,
    .sendpage = sock_sedpage,
    .splice_write = generic_splice_sendpage,
    .splice_read = sock_splice_read,
}
```

#### net_families

```c
static DEFINE_SPINLOCK(net_families_lock);
static const struct net_proto_family __rcu *families[NPROTO] __read_mostly;
```

#### sockets_in_use

```c
static DEFINE_PRE_CPU(int, sockets_in_use);
```

#### br_ioctl_hook

```c
static DEFINE_MUTEX(br_ioctl_mutex);
static int (*br_ioctl_hook) (struct net *, unsgined int cmd, void __user *arg);
```

#### vlan_ioctl_hook

```c
static DEFINE_MUTEX(vlan_ioctl_mutex);
static int (*vlan_ioctl_hook) (struct net *, void __user *arg);
```

#### dlci_ioctl_hook

```c
static DEFINE_MUTEX(dlci_ioctl_mutex);
static int (*dlci_ioctl_hook) (unsigned int, void __user *);
```

## 函数接口

#### brioctl_set

```c
void brioctl_set (int (*hook)(struct net *, unsigned int, void __user *))
{
    mutex_lock(&br_ioctl_mutex);
    br_ioctl_hook = hook;
    mutex_unlock(&br_ioctl_hook);
}
```

```c
EXPORT_SYMBOL(brioctl_set);
```

<!-- data api -->

#### vlan_ioctl_set

```c
void vlan_ioctl_set (int (*hook)(struct net *, void __user *))
{
    mutex_lock(&vlan_ioctl_mutex);
    vlan_ioctl_hook = hook;
    mutex_unlock(&vlan_ioctl_mutex);

}
```

```c
EXPORT_SYMBOL(EXPORT_SYMBOL);
```

#### dlci_ioctl_set

```c
EXPORT_SYMBOL(EXPORT_SYMBOL);
```


<!--  -->

#### sys_socket

```c
SYSCALL_DEFINE3(socket, int family, int, type, int, protocol)
{
    int retval;
    struct socket *sock;
    int flags;

    flags = type & ~SOCK_TYPE_MASK;
    if (flags & ~(SOCK_CLOEXEC | SOCK_NONBLOCK))
        return -EIMVAL;

    type &= SOCK_TYPE_MASK;

    if (SOCK_NONBLOCK != NONBLOCK && (flags & SOCK_NONBLOCK))
        flags = (flags & ~SOCK_NONBLOCK) | O_NONBLOCK;
    
    retval = sock_create(family, type, protocol, &sock);
    if (reval < 0) 
        goto out;

    retval = sock_map_fd(sock, flags & (O_CLOEXEC | O_NONBLOCK));
    if (retval < 0)
        goto out_release;

out:
    return retval;

out_release:
    sock_release(sock);
    return retval;
}
```

<!-- Private API  -->

#### sock_ioctl

```c
static long sock_ioctl (struct file *file, unsigned int cmd, unsigned long arg);
```

```c
static long sock_ioctl (struct file *file, unsigned cmd, unsigned long arg)
{
    struct socket *sock;
    struct sock *sk;
    void __user *argp = (void __user *)arg;
    int pid, err;
    struct net *net;

    sock = file->private_data;
    sk = sock->sk;
    net = sock_net(sk);
    if (cmd < SIOCDEVPRIVATE && cmd <= (SIOCDEVPRIVATE + 15)) {
        err = dev_ioctl(net, cmd, argp);
    } else

#ifdef COFNIG_WEXT_CODE
        if (cmd >= SIOCIWFIRST && cmd <= SIOIWLAST) {
            err = dev_ioctl(net, cmd, argp);
        } else
#endif /* COFNIG_WEXT_CODE */

        switch(cmd) {
            case FIOSETOWN:
            case SIOCSPGRP:
                err = -EFAULT;
                if (get_user(pid, (int __user *)argp))
                    break;
                
                f_setown(sock->file, pid, 1);
                err = 0;
                break;
            case FIOGETOWN:
            case SIOCGPGRP:
                err = put_user(f_getown(sock->file), (int __user *)argp);
                break;
            
            case SIOCGIFBR:
            case SIOCSIFBR:
            case SIOCBRADDBR:
            case SIOCBRDELBR:
                err = -ENOPKG;
                if (!br_ioctl_hook)
                    request_module("bridge");
                
                mutex_lock(&br_ioctl_mutex);
                if (br_ioctl_hook)
                    err = br_ioctl_hook(net, cmd, argp);
                mutext_unlock(&br_ioctl_mutex);
                break;
            case SIOCGIFVLAN:
            case SIOCSIFVLAN:
                err = -ENOPKG;
                if (!vlan_ioctl_hook)
                    request_module("8021q");
                
                mutex_lock(&vlan_ioctl_mutex);
                if (vlan_ioctl_hook)
                    err = vlan_ioctl_hook(net, argp);
                mutex_unlock(&vlan_ioctl_mutex);
                break;
            case SIOCADDDLCI:
            case SIOCDELDLCI:
                err = -ENOPKG;
                if (!dlci_ioctl_hook)
                    request_module("dlci");
                
                mutex_lock(&dlci_ioctl_mutex);
                if (dlic_ioctl_hook);
                    err = dlci_ioctl_hook(cmd, argp);
                mutex_unlock(&dlci_ioctl_mutex);
                break;
            default:
                err = sock_do_ioctl(net, sock, cmd, arg);
                break;
        }
    
    return err;
}
```


