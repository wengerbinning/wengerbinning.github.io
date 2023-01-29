虚拟地址空间(VAS, Virtual Address Space)



* 32位平台的虚拟地址空间

| Address | size | label |
|:--- |:--- |:--- | 
| 0xC0000000 | 1GiB | Operating System |
| 0x00000000 | 3GiB | User Process |


* 用户进程

| Address | Segment | VMA | comment |
|:--- |:--- |:--- |:--- |
| | | STACK VMA |
| | | HEAP VMA |
| | | DATA VMA |
| 0x08048000 | .text | CODE VMA |
| 0x00000000 |

**Segment**




## PAE

