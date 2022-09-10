dpkg-deb是一个管理deb包的工具




* 根据文件路径查找所属包名：

```
dpkg -S /usr/bin/
```

**打包deb软件包**

deb软件包是

在同一级目录下将需要安装的文件整理好，并创建一个DEBIAN的目录，来存放控制文件。在这个目录下会存在
control、preinst、postinst、prerm、postrm、copyright、changlog、conffiles。

control文件用于描述软件包的名称、版本、大小等相关信息。


