Git是一个免费开源分布式版本控制系统（DVCS，Distributed Version Control System），是为了快
速高效地处理所有项目的版本变迁，具有易学、体积小等特点。Git支持快速管理多个完全独立的本地分支，当推
送到远程存储仓库时，你可以指定推送的分支，在git工作中，有Working Directory、Staging Area、
Repository三个区，其中Staging Area是可以在提交之前对提交格式化和检查；git项目属于
Software Freedom Conservancy。

环境配置
======

在使用git管理之前，需要配置用户信息。git提供`git config`来配置信息。

* 用户基础配置：主要是用户名与邮箱的配置。

```shell
# 指定用户名。
git config user.name [<username>]
# 指定用户邮箱。
git config user.email [<email>]

# 查看仓库下所有配置信息。
git config --list
```

   如果没有--global参数会为当前仓库设置用户信息，当然你的工作目录必须在一个仓库下才能这样使用。

* 基础功能配置：主要是一些基础的配置。

```shell
# 指定一个默认仓库。
git config --global init.defaultBranch master

# 支持中文显示。
git config --global core.quotepath off

#配置git的编辑器为vim。
git config --global core.editor vim

# 配置全局不跟踪的文件。
git config --global core.excludesFile ~/.gitignore

# 配置添加已忽略的文件时的策略。
git config advice.addIgnoredFile false
```

可以使用`git help config`来查看git config的详细使用方法。这些配置信息都是保存在配置文件中的。相关的配置文件有：
* `~/.gitconfig`:该文件保存全局的配置信息，在设置信息使用`--global`参数可以将配置保存在该文件中。
* `<repository>/.git/config`:该文件保存仅在这一个仓库中的配置信息。


Git的使用主要有管理本地仓库、远程仓库、仓库文件、版本回溯、解决冲突、服务搭建等主要内容。

本地仓库管理
=========

* `git init`初始化一个新仓库。

仓库可以分为裸库与非裸库，裸库是没有工作区的仓库，一般在远程仓库是不需要工作区来对本地仓库进行修改，所以一般都是初始化为裸库。而在本地仓库需要
修改，所以需要初始化为非裸库。裸库与非裸库的区别是，非裸库是将仓库所有的信息维护在一个.git的子目录下，而裸库是直接维护在工作目录或指定目录下。
默认创建的是非裸库。

```shell
# 初始化一个本地仓库。缺省在当前工作目录初始化。
git init
# 初始化一个本地仓库。指定仓库的路径。
git init <path>
# 初始化一个本地仓库。初始化为一个裸库。
git init --base
```

> Note: 仓库的路径是可以是绝对路径，也可以是相对路径。如果路径不存在，git会递归的创建并初始化。


* `git status`显示当前工作区与暂存区的状态，缺省参数时忽略gitignore中文件的状态。

git-status会对比暂存区与仓库，工作区与暂存区的的文件，如果发生变化，则显示出来。

```shell
# 显示工作区状态。
git status
# 以简洁的格式显示状态。
git status -s
#　显示未跟踪的文件。
git status -u
# 显示忽略的文件。
git status --ignored
```

* `git add`来实现将文件添加到暂存区，暂存区的文件会被跟踪。

暂存区是位于工作区与仓库之前的桥梁，可以与仓库与工作区的文件进行对比；文件被添加到仓库中之前，必须被添加到暂存区；而且如果已添加到暂存区的文件
再次被修改，需要重现添加到暂存区来保持最新的修改可以被提交。所以变更包含新增文件和已添加文件的更新。所有文件需在工作区中。

```shell
# 将工作区中当前目录下需要被跟踪的变更添加到暂存区。包含隐藏文件。
git add .
# 将指定文件添加到暂存区。
git add <file path>
# 将当前工作目录下所有变更都添加到暂存区。跳过隐藏文件。
git add *
# 将指定文件添加到暂存区，将会跳过`.gitignore`文件检查。
git add -f <file path>
```

> Note: file path可以是一个工作区中的文件路径、目录路径以及模糊匹配(*.c表示所有的c文件)三种类型。

* `git commit`来对暂存区中的变更做一次提交。 对暂存区中的变更做一次提交。

提交是git维护对象，每一个提交有一个commit id来标识，一般提交必须有一个提交描述，没有描述会无法提交。通过`git commit`来进行提交。

```shell
# 将暂存区中内容做一次提交，并通过默认编辑器打开一个文件来填写描述信息。
git commit
# 将暂存区中内容做一次提交，通过-m来指定一段描述信息。
git commit -m <commit message>
# 将暂存区中内容做一次提交，通过-a参数来对暂存区的文件进行检查，如果已经被修改，则将修改内容添加到暂存区之后再做提交。
git commit -a
git commit -am <commit message>
# 将暂存区中内容做一次提交，通过-F参数来指定一个描述文件。
git commit -F <message file path>
```

* `git restore`恢复文件的变更。

恢复文件的变更需要文件已添加到仓库或暂存区才能恢复。

```shell
# 根据暂存区中内容撤销工作区的内容，执行后工作区中已被跟踪的文件，将恢复到暂存区中的状态。
git restore <file path>
# 根据仓库中内容撤销暂存区中内容，执行后暂存区恢复与仓库一致的状态。
git restore --staged <file path>
````



* `git show`来展示当前提交或指定提交的信息及内容。

```shell
git show
# 将当前提交与上一次提交的变更文件进行对比。
git show <file>
```

* `git diff`查看文件的差异，缺省参数会当前工作区与暂存区的差异。

```shell
git diff
```

* `git reset`实现撤销提交

* `git revert`实现增量撤销提交

* `git tag`设定标签：为每一次提交设定一个标签。

```shell
# 为当前分支的HEAD设定一个标签。
git tag <tag name>
# 为指定提交设定一个标签。
git tag -a <tag name> <commit id> -m <messgae>
# 显示当前分支的所有标签。
git tag
# 删除一个标签。
git tag -d <label>
```

> Note：标签相当于commit id的一个别名，是为了以后便于版本的回溯。

**git log**

`git log`是一个追溯之前提交的命令，该命令可以查看仓库的修改记录。没有参数时，默认显示当前分支的变
更记录（从当前时间向前追溯）。

* 对提交记录进行过滤。

```shell
# 仅显示修改当前目录的提交记录。
git log .

# 仅显示修改README文件的提交记录。
git log README
```

* 对比两个分支的提交记录。

```shell
# 对比dev分支中存在，但master中没有的提交。
git log dev ^master

# 查看dev较于master的新的提交。
git log dev..master

# 对比两个分支的差异。
git log dev...master

# 对比两个分支的差异，并使用左右箭头来区分是哪一个分支的。
git log --left-right dev...master
```

* 显示每个提交的信息。

```shell
# 显示提交的内容。
git log -p 

# 显示每个提交的文件名称以及文件状态。
git log --name-status

# 显示每个提交的文件名称。
git log --name-only

# 显示每个提交的变更的文件状态以及统计信息。
git log --stat

#
git log whatchanged
```



* `--follow`
* `--no-decorate, --decorate[=short|full|auto|no]`
* `--decorate-refs=<pattern>, --decorate-refs-exclude=<pattern>`
* `--source`
* `--[no-]mailmap, --[no-]user-mailmap`
* `--full-diff`
* `--log-size`
* `-L<start>,<end>:file, -L:<funcname>:<file>`

* `.gitignore`文件是一个配置文件，指定哪些文件不需要添加到仓库中。可以存在多个文件。

## 仓库文件

* 【功能】删除仓库文件：

  ```shell
  # 将文件从仓库中删除。
  git rm <file>
  ```

* 【功能】搜索仓库文件：

  ```shell
  git grep
  ```

* 【功能】显示仓库文件：
  
  ```shell
  git ls-tree
  ```

* 【功能】移动仓库文件：

  ```shell
  git mv
  ```

**

* 【功能】克隆远程仓库：

  ```shell
  # 克隆远程仓库到当前目录，这里以我github的demo作为演示。
  git clone https://github.com/wengerbinning/demo
  # 克隆远程仓库到指定目录。
  git clone <repository> <dicestory>
  # 克隆指定版本的的仓库。
  git clone <repository> --branch <branch tag> --single-branch
  ```

* 【功能】拉取远程仓库：

  ```shell
  # 拉取远程仓库并合并到到本地仓库。
  git pull
  ```

* 【功能】推送本地仓库：

```shell
# 将本地仓库的变更推送到远程仓库。
git push
# 将标签一起推送。
git push --tags
```

* 【功能】获取远程仓库：

  ```shell
  # 获取远程仓库，不与本地仓库合并。
  git fetch
  git fetch <remote label>
  ```

* 【功能】管理远程仓库：

  ```shell
  #　显示所有远程仓库。
  
  git add <remote label> <url>
  ```
  
* 设置本地仓库的上游分支，在远程仓库中新建一个与本地同名的仓库，并将远程仓库与本地仓库进行映射。

```shell
# 设置本地仓库的上游分支develop
git pull --set-upstream origin develop
git pull -u origin test:

# 设置当前分支的上游分支。
git branch --set-upstream-to=<remote branch> <lcoal branch>
```

* 取消上游分支

```shell
# 取消当前分支的上游分支。
git branch --unset-upstrean
```

远程仓库管理
=========

```shell
# 显示远程仓库。

git remote -v

# 添加远程仓库。(默认的远程仓库的标签是origin)

git remote add <remote label> <url>
# example: git remote add github github.com:wengerbinning/demo

# 删除远仓库。

git remote remove <remote label>
# example: git remote remove github

# 显示远程仓库的状态。(主要包括url、远程分支、本地分支以及两者之间的关系。)

git remote show <remote label>
# example: git remote show origin

# 更新远程仓库。

git remote update <remote label>
# example: git remote update origin

# 更新远程仓库状态。(此行为主要是在远程仓库中的远程分支已删除，但是在本地的远程分支仍存在时使用。用于将更新本地远程分支的信息。)

git remote prune <remote label>
# example: git remote prune origin

# 更新远程仓库的地址。（一般远程仓库的拉取与推送都是同一个地址，但是可以通过该行为修改；通常可以达到只能拉取但不能推送的目的。）
git remote set-url --push origin <push url>
# example: git remote set-url --push origin unknown
```

**分支管理相关**

* 【功能】新建分支：

  ```shell
  # 查看分支列表即当前所在分支。
  git branch
  # 新建一个分支。
  git branch <branch name>
  
  # 查看当前分支的最近的提交。
  git branch -v

  # 查看所有本地分支的上游分支。
  git branch -vv

  # 修改当前分支名称
  git branch -m <branch new name>

  # 修改指定分支的名称。
  git branch -m <branch old name> <branch new name> 
  ```

* 【功能】切换分支：

  ```shell
  # 切换分支。
  git checkout <branch>
  # 新建分支并切换到新建的分支。
  git checkout -b <branch>
  git checkout -b test origin/develop
  git checkout --track origin/test
  ```

* 【功能】合并分支：
  
  ```shell
  # 将指定分支合并到当前分支。默认使用fast-formad模式进行合并。丢掉分支信息。
  git merge <branch>
  # 将指定分支合并到当前分支。不使用fast-formad模式进行合并。将合并当作一次提交。
  git merge --no-ff <branch>
  ```

* 【功能】删除分支：

  ```shell
  # 删除已存在并已被合并的分支。
  git branch -d <branch>
  # 强行删除分支
  git branch -D <branch> 
  
  # 删除远程分支
  git push origin :<remote branch>
  git push origin --delete <remote branch>
  ```

**git merge**

```shell
# 合并分支
git merge <branch name>
# 放弃合并
git merge --abort
```
### 标签管理

标签有两种，一种简单标签，一种带注释的标签。

* git push origin <tag> 推送标签。

### 版本回溯

* 【功能】撤销提交变更：

  ```shell
  # 撤销一次提交的版本。
  git reset --hard <commit ID>
  ```



### 解决冲突

* 【功能】分析文件差异：

  ```shell
  git diff
  ```

* 【功能】git栈：

  ```shell
  # 将当前工作区中的内容备份到git栈中，并将工作去恢复到上次提交的状态。
  git stash
  # 将git栈中的内容恢复到工作区中。
  git stash pop
  # 显示git栈中的存储情况。
  git stash list
  # 清空git栈。
  git stash clear
  ```

* 


* .gitignore
* .gitattuributes
* .mailmap

### 补丁文件


```shell
# 指定commit id之后所有的提交都生成一个补丁。
git format-patch <commit id>
# 指定commit id生成补丁。
git format-patch -1 <commit id>
```




## 原理分析

git是一个版本控制器，由工作区、缓存区、本地仓库、远程仓库组成 


分支即一条提交的链表，master为主分区，HEAD为当前分支的最后一次提交。每一次提交包含前一次提交的commit id。

git在使用ssh连接clone的仓库时。在服务器端配置好public key之后，如果key文件的路径是自己配置的，需要在.ssh/config文件中指定private key文件的路径

```config
host <service host>
    IdentityFile ~/.ssh/key/<private file>
```




* `git reflog`查看HEAD的变化状态。


× `git symbolic-ref HEAD refs/heads/develop` 安全切换到develop分支

## LINKS

* [官方网站](https://git-scm.com/) ☛ <https://git-scm.com/>
