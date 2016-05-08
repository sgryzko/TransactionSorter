# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(CONFIG),Debug)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Debug
  OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_6D53C8B4=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ../../JuceLibraryCode -I ../../JuceLibraryCode/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0
  CXXFLAGS += $(CFLAGS) -std=c++11
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -L/usr/X11R6/lib/ -ldl -lpthread -lrt 

  TARGET := UnitTests
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

ifeq ($(CONFIG),Release)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Release
  OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_6D53C8B4=1" -D "JUCE_APP_VERSION=1.0.0" -D "JUCE_APP_VERSION_HEX=0x10000" -I /usr/include -I /usr/include/freetype2 -I ../../JuceLibraryCode -I ../../JuceLibraryCode/modules
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -O3
  CXXFLAGS += $(CFLAGS) -std=c++11
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -fvisibility=hidden -L/usr/X11R6/lib/ -ldl -lpthread -lrt 

  TARGET := UnitTests
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(OUTDIR)/$(TARGET) $(OBJDIR)
endif

OBJECTS := \
  $(OBJDIR)/FileReaderTest_7450799a.o \
  $(OBJDIR)/TransactionSorterTest_ac045d5c.o \
  $(OBJDIR)/juce_core_75b14332.o \
  $(OBJDIR)/who_owes_what_31a2d78d.o \

.PHONY: clean

$(OUTDIR)/$(TARGET): $(OBJECTS) $(RESOURCES)
	@echo Linking UnitTests
	-@mkdir -p $(BINDIR)
	-@mkdir -p $(LIBDIR)
	-@mkdir -p $(OUTDIR)
	@$(BLDCMD)

clean:
	@echo Cleaning UnitTests
	@$(CLEANCMD)

strip:
	@echo Stripping UnitTests
	-@strip --strip-unneeded $(OUTDIR)/$(TARGET)

$(OBJDIR)/FileReaderTest_7450799a.o: ../../Source/FileReaderTest.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling FileReaderTest.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/TransactionSorterTest_ac045d5c.o: ../../Source/TransactionSorterTest.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling TransactionSorterTest.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_core_75b14332.o: ../../JuceLibraryCode/juce_core.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/who_owes_what_31a2d78d.o: ../../JuceLibraryCode/who_owes_what.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling who_owes_what.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
