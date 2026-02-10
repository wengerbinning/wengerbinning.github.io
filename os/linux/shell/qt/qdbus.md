


```shell
 qdbus org.kde.konsole-$PPID
```

```shell
qdbus org.kde.konsole-$PPID /Windows/1
```
    
```shell
#
qdbus org.kde.konsole-$PPID /Sessions/1

#
qdbus org.kde.konsole-$PPID /Sessions/1 org.kde.konsole.Session.setTitle 1 konsole
```