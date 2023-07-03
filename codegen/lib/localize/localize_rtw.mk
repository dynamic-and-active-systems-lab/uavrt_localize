###########################################################################
## Makefile generated for component 'localize'. 
## 
## Makefile     : localize_rtw.mk
## Generated on : Mon Jul 03 15:19:22 2023
## Final product: ./localize.a
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# MODELLIB                Static library target

PRODUCT_NAME              = localize
MAKEFILE                  = localize_rtw.mk
MATLAB_ROOT               = /Applications/MATLAB_R2023a.app
MATLAB_BIN                = /Applications/MATLAB_R2023a.app/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/maci64
START_DIR                 = /Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/CODE_PLAYGROUND/uavrt_localize
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
C_STANDARD_OPTS           = -fno-common -fexceptions
CPP_STANDARD_OPTS         = -std=c++14 -fno-common -fexceptions
MODELLIB                  = localize.a

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Xcode with Clang | gmake (64-bit Mac)
# Supported Version(s):    
# ToolchainInfo Version:   2023a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

ARCHS             = x86_64
XCODE_SDK_VER     = $(shell perl $(MATLAB_ROOT)/rtw/c/tools/macsdkver.pl)
XCODE_SDK         = MacOSX$(XCODE_SDK_VER).sdk
XCODE_DEVEL_DIR   = $(shell xcode-select -print-path)
XCODE_SDK_ROOT    = $(XCODE_DEVEL_DIR)/Platforms/MacOSX.platform/Developer/SDKs/$(XCODE_SDK)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Clang C Compiler
CC = xcrun clang

# Linker: Clang Linker
LD = xcrun clang++

# C++ Compiler: Clang C++ Compiler
CPP = xcrun clang++

# C++ Linker: Clang C++ Linker
CPP_LD = xcrun clang++

# Archiver: Clang Archiver
AR = xcrun ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/maci64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(C_STANDARD_OPTS) -mmacosx-version-min=10.15 \
                       -O3
CPPFLAGS             = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(CPP_STANDARD_OPTS) -mmacosx-version-min=10.15 \
                       -O3
CPP_LDFLAGS          = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR)
CPP_SHAREDLIB_LDFLAGS  = -arch $(ARCHS)  \
                         -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) \
                         -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -arch $(ARCHS)  \
                       -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) \
                       -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./localize.a
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/codegen/lib/localize -I$(START_DIR) -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=localize

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/localize/coder_platform.c $(START_DIR)/codegen/lib/localize/localize_data.cpp $(START_DIR)/codegen/lib/localize/rt_nonfinite.cpp $(START_DIR)/codegen/lib/localize/rtGetNaN.cpp $(START_DIR)/codegen/lib/localize/rtGetInf.cpp $(START_DIR)/codegen/lib/localize/localize_initialize.cpp $(START_DIR)/codegen/lib/localize/localize_terminate.cpp $(START_DIR)/codegen/lib/localize/localize.cpp $(START_DIR)/codegen/lib/localize/readbearingcsv.cpp $(START_DIR)/codegen/lib/localize/fileManager.cpp $(START_DIR)/codegen/lib/localize/ftell.cpp $(START_DIR)/codegen/lib/localize/fgetl.cpp $(START_DIR)/codegen/lib/localize/str2double.cpp $(START_DIR)/codegen/lib/localize/unique.cpp $(START_DIR)/codegen/lib/localize/find.cpp $(START_DIR)/codegen/lib/localize/combineVectorElements.cpp $(START_DIR)/codegen/lib/localize/angdiff.cpp $(START_DIR)/codegen/lib/localize/vincentydistance.cpp $(START_DIR)/codegen/lib/localize/norm.cpp $(START_DIR)/codegen/lib/localize/vincentyendpoint.cpp $(START_DIR)/codegen/lib/localize/localizefrombearings.cpp $(START_DIR)/codegen/lib/localize/median.cpp $(START_DIR)/codegen/lib/localize/quickselect.cpp $(START_DIR)/codegen/lib/localize/ixfun.cpp $(START_DIR)/codegen/lib/localize/besseli.cpp $(START_DIR)/codegen/lib/localize/cospiAndSinpi.cpp $(START_DIR)/codegen/lib/localize/strcmp.cpp $(START_DIR)/codegen/lib/localize/nchoosek.cpp $(START_DIR)/codegen/lib/localize/sort.cpp $(START_DIR)/codegen/lib/localize/sortIdx.cpp $(START_DIR)/codegen/lib/localize/cosd.cpp $(START_DIR)/codegen/lib/localize/sind.cpp $(START_DIR)/codegen/lib/localize/cotd.cpp $(START_DIR)/codegen/lib/localize/gammaln.cpp $(START_DIR)/codegen/lib/localize/sqrt.cpp $(START_DIR)/codegen/lib/localize/cmlri.cpp $(START_DIR)/codegen/lib/localize/div.cpp $(START_DIR)/codegen/lib/localize/varNamesDim.cpp $(START_DIR)/codegen/lib/localize/onCleanup.cpp $(START_DIR)/codegen/lib/localize/table.cpp $(START_DIR)/codegen/lib/localize/localize_rtwutil.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = coder_platform.o localize_data.o rt_nonfinite.o rtGetNaN.o rtGetInf.o localize_initialize.o localize_terminate.o localize.o readbearingcsv.o fileManager.o ftell.o fgetl.o str2double.o unique.o find.o combineVectorElements.o angdiff.o vincentydistance.o norm.o vincentyendpoint.o localizefrombearings.o median.o quickselect.o ixfun.o besseli.o cospiAndSinpi.o strcmp.o nchoosek.o sort.o sortIdx.o cosd.o sind.o cotd.o gammaln.o sqrt.o cmlri.o div.o varNamesDim.o onCleanup.o table.o localize_rtwutil.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -lm -lstdc++

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) $(OBJS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/localize/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/localize/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


coder_platform.o : $(START_DIR)/codegen/lib/localize/coder_platform.c
	$(CC) $(CFLAGS) -o "$@" "$<"


localize_data.o : $(START_DIR)/codegen/lib/localize/localize_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/codegen/lib/localize/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/codegen/lib/localize/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/codegen/lib/localize/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


localize_initialize.o : $(START_DIR)/codegen/lib/localize/localize_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


localize_terminate.o : $(START_DIR)/codegen/lib/localize/localize_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


localize.o : $(START_DIR)/codegen/lib/localize/localize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


readbearingcsv.o : $(START_DIR)/codegen/lib/localize/readbearingcsv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fileManager.o : $(START_DIR)/codegen/lib/localize/fileManager.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ftell.o : $(START_DIR)/codegen/lib/localize/ftell.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fgetl.o : $(START_DIR)/codegen/lib/localize/fgetl.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


str2double.o : $(START_DIR)/codegen/lib/localize/str2double.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


unique.o : $(START_DIR)/codegen/lib/localize/unique.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find.o : $(START_DIR)/codegen/lib/localize/find.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


combineVectorElements.o : $(START_DIR)/codegen/lib/localize/combineVectorElements.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


angdiff.o : $(START_DIR)/codegen/lib/localize/angdiff.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


vincentydistance.o : $(START_DIR)/codegen/lib/localize/vincentydistance.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


norm.o : $(START_DIR)/codegen/lib/localize/norm.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


vincentyendpoint.o : $(START_DIR)/codegen/lib/localize/vincentyendpoint.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


localizefrombearings.o : $(START_DIR)/codegen/lib/localize/localizefrombearings.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


median.o : $(START_DIR)/codegen/lib/localize/median.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


quickselect.o : $(START_DIR)/codegen/lib/localize/quickselect.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ixfun.o : $(START_DIR)/codegen/lib/localize/ixfun.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


besseli.o : $(START_DIR)/codegen/lib/localize/besseli.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cospiAndSinpi.o : $(START_DIR)/codegen/lib/localize/cospiAndSinpi.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


strcmp.o : $(START_DIR)/codegen/lib/localize/strcmp.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


nchoosek.o : $(START_DIR)/codegen/lib/localize/nchoosek.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sort.o : $(START_DIR)/codegen/lib/localize/sort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortIdx.o : $(START_DIR)/codegen/lib/localize/sortIdx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cosd.o : $(START_DIR)/codegen/lib/localize/cosd.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sind.o : $(START_DIR)/codegen/lib/localize/sind.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cotd.o : $(START_DIR)/codegen/lib/localize/cotd.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


gammaln.o : $(START_DIR)/codegen/lib/localize/gammaln.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sqrt.o : $(START_DIR)/codegen/lib/localize/sqrt.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cmlri.o : $(START_DIR)/codegen/lib/localize/cmlri.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


div.o : $(START_DIR)/codegen/lib/localize/div.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


varNamesDim.o : $(START_DIR)/codegen/lib/localize/varNamesDim.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


onCleanup.o : $(START_DIR)/codegen/lib/localize/onCleanup.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


table.o : $(START_DIR)/codegen/lib/localize/table.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


localize_rtwutil.o : $(START_DIR)/codegen/lib/localize/localize_rtwutil.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


