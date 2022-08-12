mdev

mdev(Mini udev)是busybox中的组件，

mdev会扫描`/sys/block`和`/sys/class`的dev属性文件，从该文件可以得到设备的编号（主设备号：次设备号）。该属性文件的路径一般为
`/sys/class/*/*/dev`，其中class下的目录称为subsystem, 在subsystem下的目录称为device name，在扫描到后在`/dev`下以device name
为名称创建设备文件。



mdev一般用于嵌入式中，源码在busybox/util-linux中。