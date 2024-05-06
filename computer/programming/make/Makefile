

# $1 - from
# $2 - to
# $3 - text
define test/str/func/subst
$(subst $1, $2, $3)
endef


# $1 - pattern
# $2 - replacement
# $3 - text
define test/str/func/patsubst
$(patsubst $1, $2, $3)
endef

# $1 - text
define test/str/func/strip
$(strip $1)
endef

# $1 - find
# $2 - in
define test/str/func/findstring
$(findstring $1, $2)
endef

# $1 - pattern
# $2 - text
define test/str/func/filter
$(filter $1, $2)
endef


##

# $1 - file: It's a file path.
define test/file/func/dir
$(dir $1)
endef

# $1 - file: It's a file path.
define test/file/func/notdir
$(notdir $1)
endef


# $1 - file: It's a file path.
define test/file/func/suffix
$(suffix $1)
endef



all:
	@echo "func      subst -" $(call test/str/func/subst,AECDEF,abcdef,0xFFFFFF)
	@echo "func   patsubst -" $(call test/str/func/patsubst,%.c,%.o,helloworld.c)
	@echo "func      strip -" $(call test/str/func/strip, This is a   test string)
	@echo "func findstring -" $(call test/str/func/findstring,error,Here has an error!)
	@echo "func     filter -" $(call test/str/func/filter,%.c,helloworld.h helloworld.c helloworld.o)
#
	@echo "func    dir -" $(call test/file/func/dir,src/helloworld.c)
	@echo "func notdir -" $(call test/file/func/notdir,src/helloworld.c)
	@echo "func suffix -" $(call test/file/func/suffix,src/helloworld.c)