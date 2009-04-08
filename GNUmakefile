# Compiler flags to link shared library 
LINK_DLL_FLAGS := `sh dll-flags`

# C++ compiler 
CXX := g++

# Standard preprocessor flags (common for CC and CXX) 
CPPFLAGS := 

# Standard linker flags 
LDFLAGS := 

# Location and arguments of wx-config script 
WX_CONFIG := wx-config 

# C++ flags to use with wxWidgets code 
WX_CXXFLAGS := `$(WX_CONFIG) --cxxflags`

### Variables: ###

CPPDEPS = -MT$@ -MF`echo $@ | sed -e 's,\.o$$,.d,'` -MD
WXC_CXXFLAGS =  -g  -fPIC -DPIC $(WX_CXXFLAGS) $(CPPFLAGS) -Iinclude
WXC_OBJECTS =  \
	extra.o \
	defs.o \
	apppath.o \
	db.o \
	dragimage.o \
	eljaccelerator.o \
	eljartprov.o \
	eljbitmap.o \
	eljbrush.o \
	eljbusyinfo.o \
	eljbutton.o \
	eljcalendarctrl.o \
	eljcaret.o \
	eljcheckbox.o \
	eljchecklistbox.o \
	eljchoice.o \
	eljclipboard.o \
	eljcoldata.o \
	eljcolour.o \
	eljcolourdlg.o \
	eljcombobox.o \
	eljcommand.o \
	eljconfigbase.o \
	eljcontrol.o \
	eljctxhelp.o \
	eljcursor.o \
	eljdataformat.o \
	eljdatetime.o \
	eljdc.o \
	eljdcsvg.o \
	eljdialog.o \
	eljdialup.o \
	eljdirdlg.o \
	eljdnd.o \
	eljdrawing.o \
	eljevent.o \
	eljfiledialog.o \
	eljfilehist.o \
	eljfindrepldlg.o \
	eljfont.o \
	eljfontdata.o \
	eljfontdlg.o \
	eljframe.o \
	eljgauge.o \
	eljgrid.o \
	eljhelpcontroller.o \
	eljicnbndl.o \
	eljicon.o \
	eljimage.o \
	eljimagelist.o \
	eljipc.o \
	eljjoystick.o \
	eljlayoutconstraints.o \
	eljlistbox.o \
	eljlistctrl.o \
	eljlocale.o \
	eljlog.o \
	eljmask.o \
	eljmdi.o \
	eljmenu.o \
	eljmenubar.o \
	eljmessagedialog.o \
	eljmime.o \
	eljminiframe.o \
	eljnotebook.o \
	eljpalette.o \
	eljpanel.o \
	eljpen.o \
	eljprintdlg.o \
	eljprinting.o \
	eljprocess.o \
	eljradiobox.o \
	eljradiobutton.o \
	eljregion.o \
	eljregioniter.o \
	eljsash.o \
	eljscrollbar.o \
	eljscrolledwindow.o \
	eljsingleinst.o \
	eljsizer.o \
	eljslider.o \
	eljspinctrl.o \
	eljsplitterwindow.o \
	eljstaticbox.o \
	eljstaticline.o \
	eljstatictext.o \
	eljstatusbar.o \
	eljsystemsettings.o \
	eljtextctrl.o \
	eljthread.o \
	eljtglbtn.o \
	eljtimer.o \
	eljtipwnd.o \
	eljtoolbar.o \
	eljvalidator.o \
	eljwindow.o \
	eljwizard.o \
	ewxw_main.o \
	glcanvas.o \
	graphicscontext.o \
	image.o \
	managed.o \
	mediactrl.o \
	previewframe.o \
	printout.o \
	sound.o \
	stc.o \
	taskbaricon.o \
	textstream.o \
	treectrl.o \
	wrapper.o \
	socket.o \
	sckaddr.o
#eljrc.cpp
#eljgizmos.cpp
#eljfl.cpp
#eljplot.cpp

### Conditionally set variables: ###



### Targets: ###

all: libwxc.so libwxc.so output/func.h output/const.h

install: all

uninstall: 

clean: 
	rm -f ./*.o
	rm -f ./*.d
	rm -f include/wrapper.h.gch
	rm -f libwxc.so
	rm -f output/srclist.cc
	rm -f output/func.h
	rm -f output/const_.h
	rm -f output/const.h

libwxc.so: $(WXC_OBJECTS)
	$(CXX) $(LINK_DLL_FLAGS) -fPIC -o $@ $(WXC_OBJECTS) $(LDFLAGS) -g `$(WX_CONFIG) --libs gl,net,media,richtext,xrc,html,adv,aui,xml,core,base`

output/srclist.cc: $(WXC_OBJECTS) libwxc.so util/gfunc.cc
	g++ util/gfunc.cc `wx-config --cppflags` `wx-config --libs` -o output/gensrclist.exe -Iinclude
	./output/gensrclist.exe '$(WXC_OBJECTS)'>output/srclist.cc
	rm -f output/gensrclist.exe

output/func.h: output/srclist.cc
	g++ -E `wx-config --cppflags` -Iinclude -I. -D__EWX_PREPROCESS output/srclist.cc|sed 's/) {.*$$/)/'|grep ^EWXWEXPORT|sed 's/).*(/,"/'|sed 's/)/")/'>output/func.h

output/const.h: output/srclist.cc util/gconst.cc
	g++ -E `wx-config --cppflags` -Iinclude -I. -D__EWX_PREPROCESS output/srclist.cc|grep def_const_|sed 's/(#\(.*\),/("\1",/'>output/const_.h
	g++ util/gconst.cc -o output/const.exe -Ioutput `wx-config --cppflags` `wx-config --libs`
	./output/const.exe > output/const.h
	rm ./output/const.exe


$(WXC_OBJECTS): %.o : src/%.cpp include/wrapper.h.gch
	$(CXX) -c -o $@ $(WXC_CXXFLAGS) $(CPPDEPS) $<


#precompiled header
include/wrapper.h.gch: include/wrapper.h
	$(CXX) $(WXC_CXXFLAGS) $(CPPDEPS) $<

.PHONY: all install uninstall clean


# Dependencies tracking:
-include ./*.d
