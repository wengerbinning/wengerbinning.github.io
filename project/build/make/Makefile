


all:

TOPDIR := ${CURDIR}


clean:
	echo "Clean Project"




all:
	echo "Running build"



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
