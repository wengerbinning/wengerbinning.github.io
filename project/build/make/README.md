
* rule format

```
target : prerequisites
	recipe
```

* rule - 规则
* target - 目标
* prerequisites - 前提， 先决条件， 前提条件
* recipe - 处方、规则


#### [Built-In Rules](https://www.gnu.org/software/make/manual/html_node/Catalogue-of-Rules.html)

Here is a catalogue of predefined implicit rules which are always available
unless the makefile explicitly overrides or cancels them

#### [Pattern Rules](https://www.gnu.org/software/make/manual/html_node/Pattern-Rules.html)


#### Implicit Rules

Implicit rules tell make how to use customary techniques so that you do not have
to specify them in detail when you want to use them. For example, there is an
implicit rule for C compilation.

*  File names determine which implicit rules are run.

	For example, C compilation typically takes a .c file and makes a .o file. So
	make applies the implicit rule for C compilation when it sees this
	combination of file name endings.




* [Variables Used by Implicit Rules](https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html)
* [Chains of Implicit Rules](https://www.gnu.org/software/make/manual/html_node/Chained-Rules.html)




```
autogen.sh


configure










make

```



## LINKS


* [GNU Make](https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents)
* [GNU M4](https://www.gnu.org/software/m4/m4.html)
* [Autoconf](https://www.gnu.org/software/autoconf/autoconf.html)
* [Automake](https://www.gnu.org/software/automake/)
