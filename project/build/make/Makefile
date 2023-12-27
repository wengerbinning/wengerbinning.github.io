TOPDIR := ${CURDIR}

TMPDIR := $(TOPDIR)/tmp

all:



# Phony Targets - A phony target is one that is not really the name of a file.
#  There are two reasons to use a phony target:
#    1. To avoid a conflict with a file of the same name.
#    2. To improve performance.
# <https://www.gnu.org/software/make/manual/html_node/Phony-Targets.html>

.PHONY: all install clean

# Double-Colon Rules - explicit rules written with ‘::’ instead of ‘:’ after.
#  When a target appears in multiple rules, all the rules must be the same type:
#  all ordinary, or all double-colon. If they are double-colon, each of them is
#  independent of the others. Each double-colon rule’s recipe is executed if the
#  target is older than any prerequisites of that rule. If there are no
#  prerequisites for that rule, its recipe is always executed (even if the
#  target already exists). This can result in executing none, any, or all of the
#  double-colon rules.
# <https://www.gnu.org/software/make/manual/html_node/Double_002dColon.html>

%::







# Functions for Transforming Text. #
#  Functions allow you to do text processing in the makefile to compute the
#  files to operate on or the commands to use in recipes.

# 1. Function Call Syntax
#	<https://www.gnu.org/software/make/manual/html_node/Syntax-of-Functions.html>

# 2. Functions for String Substitution and Analysis
#	<https://www.gnu.org/software/make/manual/html_node/Text-Functions.html>

# $(subst from,to,text)
# $(patsubst pattern,replacement,text)
# $(strip string)
# $(findstring find,in)
# $(filter pattern…,text)
# $(filter-out pattern…,text)
# $(sort list)
# $(word n,text)
# $(wordlist s,e,text)
# $(words text)
# $(firstword names…)
# $(lastword names…)


# 3. Functions for File Names
#	<https://www.gnu.org/software/make/manual/html_node/File-Name-Functions.html>

# $(dir names…)
# $(notdir names…)
# $(suffix names…)
# $(basename names…)
# $(addsuffix suffix,names…)
# $(addprefix prefix,names…)
# $(join list1,list2)
# $(wildcard pattern)
# $(realpath names…)
# $(abspath names…)

# 4. Functions for Conditionals

# $(if condition,then-part[,else-part])
# $(or condition1[,condition2[,condition3…]])
# $(and condition1[,condition2[,condition3…]])
# $(intcmp lhs,rhs[,lt-part[,eq-part[,gt-part]]])

# 5. The let Function

# ---------------------------------------------------------------------------- #

define Prepare/CreateDir
	mkdir -p $1
endef

$(call Prepare/CreateDir, tmp)

clean:
	@echo "Clean Project"
	@ rm -rf tmp

all:
	@echo "Running build"

# ---------------------------------------------------------------------------- #




$(TMPDIR)/table.mk:
	(echo "module=demo") > $@.tmp
	mv $@.tmp $@


-include $(TMPDIR)/table.mk

