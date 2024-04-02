Bourne Shell




##  Bourne Shell Builtins

#### :

#### .

#### break

#### cd

#### continue

#### eval

#### exec

#### exit

#### export

#### getopts

#### hash

#### pwd

#### readonly

#### return

#### shift

#### test

#### times

#### trap

#### umask

#### unset


## Bourne Shell Variables

#### CDPATH
#### HOME
#### IFS
#### MAIL
#### MAILPATH
#### OPTARG
#### OPTIND
#### PATH
#### PS1
#### PS2



## Shell Commands


#### Pipelines
#### Lists of Commands

### Compound Commands
#### Looping Constructs

#### Conditional Constructs

##### if

```
if <test commands>; then
	<consequent-commands>
elif <more test commands>; then
    more-consequents;
else
    alternate-consequents;
fi

```

##### case

```
case word in
    [ [(] pattern [| pattern]…) command-list ;;]…
esac
```
##### select

```
select name [in words …]; do commands; done
```
##### ((...))

算数表达式

```
(( expression ))

```

##### [[...]]

逻辑表达式

```
[[ expression ]]
```


using the POSIX regcomp and regexec interfaces usually described in regex(3)

#### Grouping Commands